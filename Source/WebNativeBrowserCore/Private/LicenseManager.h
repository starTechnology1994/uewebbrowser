// Copyright (c) 2026 StarTechnology. All rights reserved.

// WebNativeBrowser 授权管理器 - 本地授权文件管理与状态查询
// 本类仅负责授权文件查找、内容传递与状态镜像（供日志与 UI 显示）。
#pragma once

#include "CoreMinimal.h"

// 授权状态
enum class EWNBLicenseStatus : uint8
{
    NotChecked,         // 未检查
    Valid,              // 有效 (未到期)
    Expired,            // 已到期
    NoLicense,          // 未找到授权文件
    Invalid,            // 授权文件无效
    TimeTampered,       // 检测到时间篡改
};

// 授权信息 (从 .license 文件解析, 供显示)
struct FWNBLicenseInfo
{
    FString LicenseKey;
    FString CustomerName;
    FString CustomerCompany;
    FString CustomerTaxId;      // 企业税号
    FString CustomerEmail;      // 联系邮箱
    FString LicenseType;        // trial / annual / decade / perpetual / enterprise
    FString IssueDate;          // 发行时间 (ISO 8601)
    FString ExpireDate;         // 到期时间 (ISO 8601)
    FString MachineId;          // 机器指纹
    FString TimeAnchor;         // 时间锚点
    TArray<FString> Features;
    FString SignatureBase64;    // 签名 (Base64)

    // 运行时解析的字段 (显示用)
    FDateTime ExpireDateTime;
    FDateTime IssueDateTime;
};

/**
 * WebNativeBrowser 授权管理器
 *
 * 管理本地授权文件（查找 / 解析 / 状态查询）。
 */
class FWebNativeBrowserLicenseManager
{
public:
    // 获取单例
    static FWebNativeBrowserLicenseManager& Get();

    // 初始化 - 插件启动时调用
    void Initialize();

    // 获取当前授权状态 (库内权威状态的只读镜像)
    EWNBLicenseStatus GetStatus() const { return CurrentStatus; }

    // 获取授权信息 (显示用)
    const FWNBLicenseInfo& GetLicenseInfo() const { return LicenseInfo; }

    // 获取机器指纹 (供用户复制发送给授权方)
    static FString GetMachineId();

    // 生成机器码文件到插件目录 (供用户复制发送给授权方)
    static void GenerateMachineIdFile();

    // 编辑器下：授权有效时把服务器签发的机器绑定标记 webnative_bridge.dat
    // 从 Saved/licenses/ 同步到插件 Content/webnative/licenses/（随包分发）
    bool GenerateBuildMetaFile();

    // 获取服务器签发构建标记文件路径（打包版从 pak 逻辑路径读取）
    FString GetBuildMetaFilePath() const;

    // 获取授权状态描述文字 (用于UI显示)
    FString GetStatusDescription() const;

    // 重新加载授权文件 (用户放入新授权后调用)
    void ReloadLicense();

private:
    FWebNativeBrowserLicenseManager() = default;

    // 解析 .license 文件 (字段提取, 供显示)
    bool ParseLicenseFile(const FString& FilePath);

    // 获取授权文件路径
    FString GetLicenseFilePath() const;

    // 获取运行记录文件路径
    FString GetRunRecordPath() const;

    // --- 状态 ---

    EWNBLicenseStatus CurrentStatus = EWNBLicenseStatus::NotChecked;
    FWNBLicenseInfo LicenseInfo;
    FString RawJsonContent;  // 原始JSON内容 (仅日志脱敏用)
    bool bInitialized = false;
};
