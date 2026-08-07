// Copyright (c) 2026 StarTechnology. All rights reserved.

// WebNativeBrowser Editor Module — 场景生成器
// 跨平台兼容 UE 5.1-5.8

#include "WebNativeBrowserEditorModule.h"

#include "EditorSubsystem.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ToolMenus.h"
#include "LevelEditor.h"
#include "ActorFactories/ActorFactory.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Editor.h"
#include "EditorViewportClient.h"
#include "LevelEditorViewport.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "FWebNativeBrowserEditorModule"

// 跨版本 ToolMenus 兼容
#if ENGINE_MAJOR_VERSION == 5
    #if ENGINE_MINOR_VERSION >= 1
        #define WNB_USE_TOOL_MENUS 1
    #else
        #define WNB_USE_TOOL_MENUS 0
    #endif
#else
    #define WNB_USE_TOOL_MENUS 0
#endif

// 场景物体定义
struct FSceneObject
{
    FString MeshPath;       // /Engine/BasicShapes/...
    FVector Location;
    FRotator Rotation;
    FVector Scale;
    FString MaterialPath;   // 材质路径
    FLinearColor Color;     // 颜色
    FString Label;
};

// 创建材质实例（跨版本兼容）
static UMaterialInstanceDynamic* CreateColoredMaterial(UObject* WorldContext, const FString& MaterialPath, const FLinearColor& Color)
{
    // 使用引擎自带基础材质
    static UMaterialInterface* BaseMaterial = nullptr;
    if (!BaseMaterial)
    {
        BaseMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
    }

    if (!BaseMaterial)
    {
        return nullptr;
    }

    UMaterialInstanceDynamic* DynMat = UMaterialInstanceDynamic::Create(BaseMaterial, WorldContext);
    if (DynMat)
    {
        DynMat->SetVectorParameterValue(FName(TEXT("Color")), Color);
    }
    return DynMat;
}

// 在关卡中生成单个物体
static AStaticMeshActor* SpawnSceneObject(UWorld* World, const FSceneObject& ObjDef)
{
    if (!World) return nullptr;

    // 加载静态网格
    UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, *ObjDef.MeshPath);
    if (!Mesh)
    {
        UE_LOG(LogTemp, Warning, TEXT("WebNativeBrowser Editor: 无法加载网格 %s"), *ObjDef.MeshPath);
        return nullptr;
    }

    // 生成 Actor
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    AStaticMeshActor* Actor = World->SpawnActor<AStaticMeshActor>(ObjDef.Location, ObjDef.Rotation, SpawnParams);
    if (!Actor) return nullptr;

    Actor->SetActorLabel(*ObjDef.Label);
    Actor->SetActorScale3D(ObjDef.Scale);

    // 设置网格
    UStaticMeshComponent* MeshComp = Actor->GetStaticMeshComponent();
    if (MeshComp)
    {
        MeshComp->SetStaticMesh(Mesh);
        MeshComp->SetMobility(EComponentMobility::Movable);
        MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        MeshComp->SetCollisionObjectType(ECC_WorldStatic);

        // 设置材质
        UMaterialInstanceDynamic* DynMat = CreateColoredMaterial(Actor, ObjDef.MaterialPath, ObjDef.Color);
        if (DynMat)
        {
            MeshComp->SetMaterial(0, DynMat);
        }
    }

    return Actor;
}

// 生成完整场景
static void SpawnDigitalTwinScene()
{
    UWorld* World = GWorld;
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("WebNativeBrowser Editor: 没有当前关卡"));
        return;
    }

    const FScopedTransaction Transaction(FText::FromString(TEXT("生成数字孪生场景")));

    // 颜色定义
    const FLinearColor GroundColor(0.15f, 0.15f, 0.18f, 1.0f);
    const FLinearColor BuildingColor(0.35f, 0.45f, 0.65f, 1.0f);
    const FLinearColor BuildingColor2(0.45f, 0.35f, 0.25f, 1.0f);
    const FLinearColor TankColor(0.65f, 0.55f, 0.25f, 1.0f);
    const FLinearColor SphereColor(0.75f, 0.25f, 0.25f, 1.0f);
    const FLinearColor ConeColor(0.25f, 0.65f, 0.45f, 1.0f);
    const FLinearColor PipeColor(0.4f, 0.4f, 0.42f, 1.0f);
    const FLinearColor WallColor(0.2f, 0.2f, 0.22f, 1.0f);
    const FLinearColor LightColor(1.0f, 0.95f, 0.6f, 1.0f);
    const FLinearColor PoleColor(0.2f, 0.2f, 0.2f, 1.0f);

    // 场景物体定义 — 50m×50m 工业园区, 中心留空
    TArray<FSceneObject> Objects;

    // ====== 地面 (50m×50m) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(0, 0, 0), FRotator(0, 0, 0), FVector(50, 50, 0.1f),
        TEXT(""), GroundColor, TEXT("Ground") });

    // ====== 主体建筑 (四角分布) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(-1800, -1500, 200), FRotator(0, 0, 0), FVector(4, 6, 4),
        TEXT(""), BuildingColor, TEXT("Building_A") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(1800, -1500, 180), FRotator(0, 0, 0), FVector(4, 5, 3.6f),
        TEXT(""), BuildingColor, TEXT("Building_B") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(-1800, 1500, 150), FRotator(0, 0, 0), FVector(5, 4, 3),
        TEXT(""), BuildingColor2, TEXT("Warehouse") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(1800, 1500, 120), FRotator(0, 0, 0), FVector(3, 3, 2.4f),
        TEXT(""), BuildingColor2, TEXT("Power_Station") });

    // ====== 储罐区 (左侧) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-1500, -500, 250), FRotator(0, 0, 0), FVector(1.5f, 1.5f, 5),
        TEXT(""), TankColor, TEXT("Oil_Tank_1") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-1200, -500, 220), FRotator(0, 0, 0), FVector(1.2f, 1.2f, 4.4f),
        TEXT(""), TankColor, TEXT("Oil_Tank_2") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-1500, 500, 250), FRotator(0, 0, 0), FVector(1.5f, 1.5f, 5),
        TEXT(""), TankColor, TEXT("Oil_Tank_3") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Sphere.Sphere"),
        FVector(1500, -500, 150), FRotator(0, 0, 0), FVector(2, 2, 2),
        TEXT(""), SphereColor, TEXT("Sphere_Tank") });

    // ====== 冷却塔 (右侧) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cone.Cone"),
        FVector(1200, 500, 200), FRotator(0, 0, 0), FVector(2, 2, 4),
        TEXT(""), ConeColor, TEXT("Cooling_Tower_1") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cone.Cone"),
        FVector(1500, 500, 180), FRotator(0, 0, 0), FVector(1.5f, 1.5f, 3.6f),
        TEXT(""), ConeColor, TEXT("Cooling_Tower_2") });

    // ====== 管道 (建筑之间) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-500, -1000, 80), FRotator(0, 90, 0), FVector(0.4f, 3, 0.4f),
        TEXT(""), PipeColor, TEXT("Pipe_1") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(500, -1000, 80), FRotator(0, 90, 0), FVector(0.4f, 4, 0.4f),
        TEXT(""), PipeColor, TEXT("Pipe_2") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-900, 0, 200), FRotator(90, 0, 0), FVector(0.4f, 3, 0.4f),
        TEXT(""), PipeColor, TEXT("Pipe_3") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(900, 0, 150), FRotator(90, 0, 0), FVector(0.4f, 3, 0.4f),
        TEXT(""), PipeColor, TEXT("Pipe_4") });

    // ====== 围墙 (50m×50m) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(0, -2500, 100), FRotator(0, 0, 0), FVector(50, 0.2f, 2),
        TEXT(""), WallColor, TEXT("Wall_Front") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(0, 2500, 100), FRotator(0, 0, 0), FVector(50, 0.2f, 2),
        TEXT(""), WallColor, TEXT("Wall_Back") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(-2500, 0, 100), FRotator(0, 0, 0), FVector(0.2f, 50, 2),
        TEXT(""), WallColor, TEXT("Wall_Left") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cube.Cube"),
        FVector(2500, 0, 100), FRotator(0, 0, 0), FVector(0.2f, 50, 2),
        TEXT(""), WallColor, TEXT("Wall_Right") });

    // ====== 路灯 (四角) ======
    Objects.Add({ TEXT("/Engine/BasicShapes/Sphere.Sphere"),
        FVector(2200, -2200, 400), FRotator(0, 0, 0), FVector(0.6f, 0.6f, 0.6f),
        TEXT(""), LightColor, TEXT("Lamp_1") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Sphere.Sphere"),
        FVector(-2200, -2200, 400), FRotator(0, 0, 0), FVector(0.6f, 0.6f, 0.6f),
        TEXT(""), LightColor, TEXT("Lamp_2") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Sphere.Sphere"),
        FVector(2200, 2200, 400), FRotator(0, 0, 0), FVector(0.6f, 0.6f, 0.6f),
        TEXT(""), LightColor, TEXT("Lamp_3") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Sphere.Sphere"),
        FVector(-2200, 2200, 400), FRotator(0, 0, 0), FVector(0.6f, 0.6f, 0.6f),
        TEXT(""), LightColor, TEXT("Lamp_4") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(2200, -2200, 200), FRotator(0, 0, 0), FVector(0.2f, 0.2f, 4),
        TEXT(""), PoleColor, TEXT("Lamp_Pole_1") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-2200, -2200, 200), FRotator(0, 0, 0), FVector(0.2f, 0.2f, 4),
        TEXT(""), PoleColor, TEXT("Lamp_Pole_2") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(2200, 2200, 200), FRotator(0, 0, 0), FVector(0.2f, 0.2f, 4),
        TEXT(""), PoleColor, TEXT("Lamp_Pole_3") });

    Objects.Add({ TEXT("/Engine/BasicShapes/Cylinder.Cylinder"),
        FVector(-2200, 2200, 200), FRotator(0, 0, 0), FVector(0.2f, 0.2f, 4),
        TEXT(""), PoleColor, TEXT("Lamp_Pole_4") });

    // 生成所有物体
    int32 SpawnedCount = 0;
    for (const FSceneObject& Obj : Objects)
    {
        if (SpawnSceneObject(World, Obj))
        {
            SpawnedCount++;
        }
    }

    UE_LOG(LogTemp, Log, TEXT("WebNativeBrowser Editor: 场景生成完成, 共 %d 个物体"), SpawnedCount);

    // 刷新视口
    if (GEditor)
    {
        GEditor->RedrawAllViewports();
    }
}

void FWebNativeBrowserEditorModule::StartupModule()
{
#if WNB_USE_TOOL_MENUS
    // UE 5.1+ 使用 ToolMenus
    UToolMenus::RegisterStartupCallback(
        FSimpleMulticastDelegate::FDelegate::CreateLambda([this]()
        {
            RegisterMenus();
        }));
#else
    // UE 5.0 使用旧版菜单
    FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
    TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
    MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, nullptr, FMenuExtensionDelegate::CreateLambda([](FMenuBuilder& MenuBuilder)
    {
        MenuBuilder.AddMenuEntry(
            FText::FromString(TEXT("生成数字孪生场景")),
            FText::FromString(TEXT("在当前关卡中生成工业园区场景")),
            FSlateIcon(),
            FUIAction(FExecuteAction::CreateStatic(&SpawnDigitalTwinScene))
        );
    }));
    LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
#endif
}

void FWebNativeBrowserEditorModule::ShutdownModule()
{
}

void FWebNativeBrowserEditorModule::RegisterMenus()
{
    UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
    FToolMenuSection& Section = Menu->FindOrAddSection("WebNativeBrowser");
    Section.Label = FText::FromString("WebNative Browser");
    Section.AddMenuEntry(
        FName("WebNativeBrowser_SpawnScene"),
        FText::FromString(TEXT("生成数字孪生场景")),
        FText::FromString(TEXT("在当前关卡中生成工业园区场景")),
        FSlateIcon(),
        FUIAction(FExecuteAction::CreateStatic(&SpawnDigitalTwinScene))
    );
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FWebNativeBrowserEditorModule, WebNativeBrowserEditor)
