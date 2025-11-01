#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Ioctl's have the command encoded in the lower word, and the size of
 * any in or out parameters in the upper word.  The high 3 bits of the
 * upper word are used to encode the in/out status of the parameter.
 */
#define	IOCPARM_SHIFT	13		/* number of bits for ioctl size */
#define	IOCPARM_MASK	((1 << IOCPARM_SHIFT) - 1) /* parameter length mask */
#define	IOCPARM_LEN(x)	(((x) >> 16) & IOCPARM_MASK)
#define	IOCBASECMD(x)	((x) & ~(IOCPARM_MASK << 16))
#define	IOCGROUP(x)	(((x) >> 8) & 0xff)
#define IOCTL_NUM(cmd) ((cmd) & 0xFF) // Extracting the lower 8 bits

#define	IOCPARM_MAX	(1 << IOCPARM_SHIFT) /* max size of ioctl */
#define	IOC_VOID	0x20000000	/* no parameters */
#define	IOC_OUT		0x40000000	/* copy out parameters */
#define	IOC_IN		0x80000000	/* copy in parameters */
#define	IOC_INOUT	(IOC_IN|IOC_OUT)
#define	IOC_DIRMASK	(IOC_VOID|IOC_OUT|IOC_IN)

#define	_IOC(inout,group,num,len)	((unsigned long) \
	((inout) | (((len) & IOCPARM_MASK) << 16) | ((group) << 8) | (num)))
#define	_IO(g,n)	_IOC(IOC_VOID,	(g), (n), 0)
#define	_IOWINT(g,n)	_IOC(IOC_VOID,	(g), (n), sizeof(int))
#define	_IOR(g,n,t)	_IOC(IOC_OUT,	(g), (n), sizeof(t))
#define	_IOW(g,n,t)	_IOC(IOC_IN,	(g), (n), sizeof(t))
 /* this should be _IORW, but stdio got there first */
#define	_IOWR(g,n,t)	_IOC(IOC_INOUT,	(g), (n), sizeof(t))

#if defined(__cplusplus)
};
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
    uint64_t* Result;
};

struct Input_AuthId
{
    int ProcessId;
    uint64_t AuthId;
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
#define KERN_READ_WRITE_MEMORY _IOC(IOC_INOUT, 'K', (uint32_t)(CMD_KERN_READ_WRITE_MEMORY), sizeof(struct Input_ReadWriteMemory))
