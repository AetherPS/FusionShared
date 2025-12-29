#pragma once

#ifdef __ORBIS__
#include <sys/ioccom.h>
#else
#include <Types/ioccom.h>
#endif

enum FusionDriverCommands
{
    /* ###### FusionDriver Commands ###### */
    CMD_FUSIONDRIVER_INFO,
    /* ############################## */

    /* ######## Proc Commands ####### */
    CMD_PROC_JAILBREAK,
    CMD_PROC_JAIL,
    CMD_PROC_MODULE_LIST = 4,
    CMD_PROC_READ_WRITE_MEMORY,
    CMD_PROC_ALLOC_MEMORY,
    CMD_PROC_FREE_MEMORY,
    CMD_PROC_START_THREAD,
    CMD_PROC_RESOLVE,
	CMD_PROC_GET_AUTHID = 11,
	CMD_PROC_SET_AUTHID,
    /* ############################## */

    /* ###### Kernel Commands ####### */
    CMD_KERN_GET_BASE = 20,
    CMD_KERN_READ_WRITE_MEMORY,
    CMD_KERN_ICC_NVS_READ_WRITE,
    /* ############################## */
};

struct FusionDriverInfo
{
    int MajorVersion;
    int MinorVersion;
    int BuildVersion;
};

struct JailBackup
{
    uint32_t cr_uid;
    uint32_t cr_ruid;
    uint32_t cr_rgid;
    uint64_t cr_groups;
    uint64_t cr_sceAuthID;
    uint64_t cr_sceCaps[2];
    void* cr_prison;

    void* fd_jdir;
    void* fd_rdir;

    char RandomizedPath[0x100];
};

struct Input_Jailbreak
{
    int ProcessId;
    struct JailBackup* Jail;
    uint64_t AuthId;
    bool NullRandPath;
};

struct Input_RestoreJail
{
    int ProcessId;
    struct JailBackup Jail;
};

struct OrbisLibraryInfo
{
    uint32_t Handle;
    char Path[256];
    uint64_t MapBase;
    size_t MapSize;
    size_t TextSize;
    uint64_t DataBase;
    size_t DataSize;
};

struct Input_LibraryList
{
    int ProcessId;
    struct OrbisLibraryInfo* LibraryListOut;
    int MaxOutCount;
    int* LibraryCount;
};

struct Input_ReadWriteMemory
{
    int ProcessId;
    uint64_t ProcessAddress;
    void* DataAddress;
    size_t Length;
    bool IsWrite;
};

struct Input_AllocMemory
{
    int ProcessId;
    uint64_t* OutAddress;
    size_t Length;
    int Protection;
    int Flags;
};

struct Input_FreeMemory
{
    int ProcessId;
    uint64_t ProcessAddress;
    size_t Length;
};

struct Input_StartThreadInfo
{
    int ProcessId;
    uint64_t ThreadEntry;
    uint64_t StackMemory;
    size_t StackSize;
};

struct Input_ResolveInfo
{
    int ProcessId;
    int Handle;
    char Library[256];
    char Symbol[4096];
    unsigned int Flags;
    uint64_t Address;
};

struct Input_AuthId
{
    int ProcessId;
    uint64_t AuthId;
};

struct Input_KernelBase
{
    uint64_t KernelBase;
};

struct Input_IccNvsReadWrite
{
    uint32_t Block;
    uint32_t Offset;
    uint32_t Size;
    uint8_t* Value;
    bool IsWrite;
};

/* ###### FusionDriver Commands ###### */
#define FUSION_DRIVERINFO _IOC(IOC_OUT, 'D', (uint32_t)(CMD_FUSIONDRIVER_INFO), sizeof(struct FusionDriverInfo))

/* ######## Proc Commands ####### */
#define PROC_JAILBREAK _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_JAILBREAK), sizeof(struct Input_Jailbreak))
#define PROC_JAIL _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_JAIL), sizeof(struct Input_RestoreJail))
#define PROC_MODULE_LIST _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_MODULE_LIST), sizeof(struct Input_LibraryList))
#define PROC_READ_WRITE_MEMORY _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_READ_WRITE_MEMORY), sizeof(struct Input_ReadWriteMemory))
#define PROC_ALLOCATE_MEMORY _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_ALLOC_MEMORY), sizeof(struct Input_AllocMemory))
#define PROC_FREE_MEMORY _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_FREE_MEMORY), sizeof(struct Input_FreeMemory))
#define PROC_START_THREAD _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_START_THREAD), sizeof(struct Input_StartThreadInfo))
#define PROC_RESOLVE _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_RESOLVE), sizeof(struct Input_ResolveInfo))
#define PROC_GET_AUTHID _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_GET_AUTHID), sizeof(struct Input_AuthId))
#define PROC_SET_AUTHID _IOC(IOC_INOUT, 'P', (uint32_t)(CMD_PROC_SET_AUTHID), sizeof(struct Input_AuthId))

/* ###### Kernel Commands ####### */
#define KERN_GET_BASE _IOC(IOC_OUT, 'K', (uint32_t)(CMD_KERN_GET_BASE), sizeof(Input_KernelBase))
#define KERN_READ_WRITE_MEMORY _IOC(IOC_INOUT, 'K', (uint32_t)(CMD_KERN_READ_WRITE_MEMORY), sizeof(struct Input_ReadWriteMemory))
#define KERN_ICC_NVS_READ_WRITE _IOC(IOC_INOUT, 'K', (uint32_t)(CMD_KERN_ICC_NVS_READ_WRITE), sizeof(struct Input_IccNvsReadWrite))