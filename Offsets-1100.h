#pragma once

#if defined(VERSION_1100)

/* Util */
#define addr_Xfast_syscall		                0x000001C0
#define addr_sysvec                             0x1A6C4C8
#define addr_kernel_map                         0x21FF130
#define addr_prison0                            0x111F830
#define addr_rootvnode                          0x2116640
#define addr_copyin								0x2DDFE0
#define addr_copyout							0x2DDEF0
#define addr_DirectMemoryHook					0x404FC0

/* STD Lib */
#define addr_M_TEMP                             0x1A52100
#define addr_M_MOUNT                            0x1A6ACC0
#define addr_malloc								0x1A4220
#define addr_free					    		0x1A43E0
#define addr_memcpy								0x2DDDF0
#define addr_memset								0x482D0
#define addr_memcmp								0x948B0
#define addr_strlen                             0x21DC40
#define addr_strcpy								0x1AA590
#define addr_strncpy                            0x2BBFD0
#define addr_strcmp                             0x443130
#define addr_strncmp                            0x313B10 
#define addr_strstr                             0x2C5740
#define addr_sprintf                            0x2FCE10
#define addr_snprintf                           0x2FCED0
#define addr_vsprintf                           0x2FCEA0
#define addr_vprintf                            0x2FCC40
#define addr_sscanf                             0x54A60
#define addr_strdup                             0x32DDD0
#define addr_realloc                            0x1A44E0
#define addr_kprintf                            0x2FCBD0

/* Kproc */
#define addr_kproc_create					    0xC3140
#define addr_kproc_exit                         0xC33B0
#define addr_kproc_resume                       0xC3500
#define addr_kproc_shutdown                     0x198950
#define addr_kproc_start                        0xC30C0
#define addr_kproc_suspend                      0xC3460
#define addr_kproc_suspend_check                0xC3590
#define addr_kproc_kthread_add				    0xC3EB0
#define addr_pause                              0x3663E0
#define addr_kthread_add						0xC36A0
#define addr_kthread_exit						0xC3990
#define addr_kthread_suspend					0
#define addr_kthread_suspend_check				0xC3DA0
#define addr_kthread_set_affinity				0xC4000

/* Proc */
#define addr_allproc_lock                       0x22D0A38
#define addr_allproc						    0x22D0A98
#define addr_proc_kill                          0x44FC0
#define addr_proc_rwmem							0x3838A0
#define addr_create_thread                      0x295170

/* ptrace */
#define addr_kptrace                            0x3841B0
#define addr_kpsignal                           0x155BF0
#define addr_kwait                              0x409340
#define addr_kDelay                             0x407760

/* Virtual Memory */
#define addr_vmspace_acquire_ref				0x357720
#define addr_vmspace_free						0x357550
#define addr_vm_map_lock_read					0x3578B0
#define addr_vm_map_unlock_read					0x357900
#define addr_vm_map_lookup_entry				0x357EF0
#define addr_vm_map_findspace					0x35A970
#define addr_vm_map_insert						0x358AB0
#define addr_vm_map_lock						0x357760
#define addr_vm_map_unlock 						0x3577D0
#define addr_vm_map_delete						0x35A3B0
#define addr_vm_map_protect						0x35C710

/* Mutex Locks */
#define addr_mtx_init                           0x10F110
#define addr_mtx_destroy                        0x10F180
#define addr_mtx_lock_flags                     0x10E6A0
#define addr_mtx_unlock_flags                   0x10E950

#define addr__sx_slock                          0xE2D90
#define addr__sx_sunlock                        0xE3310
#define addr_sx_xlock							0xE3200
#define addr_sx_xunlock							0xE33C0

/* Critical Sections */
#define addr_EnterCriticalSection               0
#define addr_ExitCriticalSection                0

/* Event Handling */
#define addr_eventhandler_register              0x43E440
#define addr_eventhandler_deregister            0x43E7D0
#define addr_eventhandler_find_list             0x43E9C0

/* Trap Hooks */
#define addr_trapHook                           0
#define addr_trap_fatalHook                     0x3C60A0

/* Driver */
#define addr_make_dev_p                         0x2F7610
#define addr_destroy_dev                        0x2F7B30

/* kmem */
#define addr_kmem_alloc                         0x245E10
#define addr_kmem_free                          0x245FE0
#define addr_kernel_map                         0x21FF130

/* File IO */
#define addr_vn_fullpath                        0x3C9B10
#define addr_kern_rmdir                         0xEB810
#define addr_kern_mkdir                         0xEB490
#define addr_kern_open                          0xE6350
#define addr_kern_writev                        0xDD340
#define addr_kern_mount                         0x38BCA0
#define addr_mount_argf                         0x38BB00

/* FSelfs */
#define addr_sceSblAuthMgrGetSelfInfo						0x6437D0
#define addr_sceSblAuthMgrSmStart							0x63E9C0
#define addr_sceSblAuthMgrVerifyHeader						0x642FF0
#define addr_sbl_drv_msg_mtx								0x2646690
#define addr_gpu_va_page_list								0x2646688
#define addr_mini_syscore_self_binary						0x155CC48
#define addr_sceSblAuthMgrVerifyHeaderHook1					0x63DA26
#define addr_sceSblAuthMgrVerifyHeaderHook2					0x63E709
#define addr_SceSblAuthMgrIsLoadable2Hook					0x63D28E
#define addr_SceSblAuthMgrSmLoadSelfSegment_Mailbox			0x640E0D
#define addr_SceSblAuthMgrSmLoadSelfBlock_Mailbox			0x641A48
#define addr_sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId	0x63D13C

/* Fake Pkgs */
#define addr_sbl_keymgr_buf_gva								0x2664808
#define addr_sbl_keymgr_buf_va								0x2664000
#define addr_sbl_keymgr_key_slots							0x26606E8
#define addr_sbl_keymgr_key_rbtree							0x26606F8
#define addr_sbl_pfs_sx										0x264C080
#define addr_fpu_ctx										0x2660180
#define addr_fpu_kern_enter									0xC0660
#define addr_fpu_kern_leave									0xC0720
#define addr_Sha256Hmac										0x2D1CA0
#define addr_sceSblDriverSendMsg							0x61AF60
#define addr_sceSblPfsSetKeys								0x61D900
#define addr_RsaesPkcs1v15Dec2048CRT						0x3C8060
#define addr_AesCbcCfb128Encrypt							0x2DEAA0
#define addr_AesCbcCfb128Decrypt							0x2DECD0
#define addr_sceSblKeymgrSetKeyForPfs						0x625DF0
#define addr_sceSblKeymgrClearKey							0x626130
#define addr_sceSblKeymgrSetKeyStorage						0x62EDC0

#define addr_SceSblDriverSendMsgHook						0x62EE65
#define addr_SceSblPfsSetKeysHook							0x6993B9
#define addr_NpdrmDecryptIsolatedRifHook					0x64D230
#define addr_NpdrmDecryptRifNewHook							0x64DFFE
#define addr_SceSblKeymgrInvalidateKeySxXlockHook			0x626FAD

/* Library Replacement */
#define addr_load_prx					0x85100

/* ShellCore Patches */
#define addr_sceKernelIsGenuineCEX1		0x16B664
#define addr_sceKernelIsGenuineCEX2		0x86BD24
#define addr_sceKernelIsGenuineCEX3		0x8BC022
#define addr_sceKernelIsGenuineCEX4		0xA1D6C4

#define addr_sceKernelIsAssistMode1		0x16B692
#define addr_sceKernelIsAssistMode2		0x86BD52
#define addr_sceKernelIsAssistMode3		0x249E0C
#define addr_sceKernelIsAssistMode4		0xA1D6F2

#define addr_enableFpkg					0x3D7C9F
#define addr_fakeText					0xFC8439
#define addr_mountDataIntoSandbox		0x31F070
#define addr_disableCoreDumps			0x2ECF2B
#define addr_disableUpdateChecks		0x3C73F0

#define addr_disablePkgPatchCheck1		0x3C41A7
#define addr_disablePkgPatchCheck2		0x134A50
#define addr_disablePkgPatchCheck3		0

/* ShellUI Patches */
#define sceKernelGetDebugMenuModeForRcmgr		0x1D100
#define sceKernelGetUtokenStoreModeForRcmgr		0x1D460

#endif