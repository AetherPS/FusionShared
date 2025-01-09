#pragma once

#if defined(VERSION_900)

/* Util */
#define addr_Xfast_syscall		                0x000001C0
#define addr_sysvec                             0x01528E30
#define addr_kernel_map                         0x02268D48
#define addr_prison0                            0x0111F870 
#define addr_rootvnode                          0x021EFF20
#define addr_copyin								0x002716A0
#define addr_copyout							0x002715B0
#define addr_DirectMemoryHook					0x11D250

/* STD Lib */
#define addr_M_TEMP                             0x015621E0
#define addr_M_MOUNT                            0x015279F0
#define addr_malloc								0x00301B20
#define addr_free					    		0x00301CE0
#define addr_memcpy								0x002714B0
#define addr_memset								0x001496C0
#define addr_memcmp								0x00271E20
#define addr_strlen                             0x0030F450
#define addr_strcpy								0x00189F80
#define addr_strncpy                            0x0041E380
#define addr_strcmp                             0x0040E700
#define addr_strncmp                            0x00124750 
#define addr_strstr                             0x00487AB0
#define addr_sprintf                            0x000B7C70
#define addr_snprintf                           0x000B7D30
#define addr_vsprintf                           0x000B7D00
#define addr_vprintf                            0x000B7AA0
#define addr_sscanf                             0x0026C8D0
#define addr_strdup                             0x00278540
#define addr_realloc                            0x00301DE0
#define addr_kprintf                            0x000B7A30

/* Kproc */
#define addr_kproc_create					    0x000969E0
#define addr_kproc_exit                         0x00096C50
#define addr_kproc_resume                       0x00096DA0
#define addr_kproc_shutdown                     0x0029AC80
#define addr_kproc_start                        0x00096960
#define addr_kproc_suspend                      0x00096D00
#define addr_kproc_suspend_check                0x00096E30
#define addr_kproc_kthread_add				    0x00097750
#define addr_pause                              0x00453EA0
#define addr_kthread_add						0x00096F40
#define addr_kthread_exit						0x00097230
#define addr_kthread_suspend					0x0
#define addr_kthread_suspend_check				0x00097640
#define addr_kthread_set_affinity				0x000978A0

/* Module Offsets */
#define addr_thr_initial_libkernel              0x0008E430
#define addr_thr_initial_libkernel_web          0x0008E430
#define addr_thr_initial_libkernel_sys          0x0008E830

/* Proc */
#define addr_allproc_lock                       0x01B94680
#define addr_allproc						    0x01B946E0
#define addr_proc_kill                          0x00029780
#define addr_proc_rwmem							0x0041EB00
#define addr_create_thread                      0x001ED670

/* ptrace */
#define addr_kptrace                            0x0041F410
#define addr_kpsignal                           0x002F9BA0
#define addr_kwait                              0x00174110
#define addr_kDelay                             0x0018A6B0

/* Virtual Memory */
#define addr_vmspace_acquire_ref				0x0007B9E0
#define addr_vmspace_free						0x0007B810
#define addr_vm_map_lock_read					0x0007BB80
#define addr_vm_map_unlock_read					0x0007BBD0
#define addr_vm_map_lookup_entry				0x0007C1C0
#define addr_vm_map_findspace					0x0007EC40
#define addr_vm_map_insert						0x0007CD80 
#define addr_vm_map_lock						0x0007BA30
#define addr_vm_map_unlock 						0x0007BAA0
#define addr_vm_map_delete						0x0007E680
#define addr_vm_map_protect						0x000809C0

/* Mutex Locks */
#define addr_mtx_init                           0x002EF960
#define addr_mtx_destroy                        0x002EF9D0
#define addr_mtx_lock_flags                     0x002EEEB0
#define addr_mtx_unlock_flags                   0x002EF170

#define addr__sx_slock                          0x0043E1A0
#define addr__sx_sunlock                        0x0043E710
#define addr_sx_xlock							0x0043E610
#define addr_sx_xunlock							0x0043E7D0

/* Critical Sections */
#define addr_EnterCriticalSection               0x0
#define addr_ExitCriticalSection                0x0

/* Event Handling */
#define addr_eventhandler_register              0x000F8370
#define addr_eventhandler_deregister            0x000F8700
#define addr_eventhandler_find_list             0x000F88F0

/* Trap Hooks */
#define addr_trapHook                           0x0
#define addr_trap_fatalHook                     0x002DF710

/* Driver */
#define addr_make_dev_p                         0x001EF590
#define addr_destroy_dev                        0x001EFAB0

/* kmem */
#define addr_kmem_alloc                         0x0037BE70
#define addr_kmem_free                          0x0037C040
#define addr_kernel_map                         0x02268D48

/* File IO */
#define addr_vn_fullpath                        0x002648C0
#define addr_kern_rmdir                         0x001DF3A0
#define addr_kern_mkdir                         0x001DF020
#define addr_kern_open                          0x001D9EE0
#define addr_kern_writev                        0x0044F1B0
#define addr_kern_mount                         0x0004DF50
#define addr_mount_argf                         0x0004DDB0

/* FSelfs */
#define addr_sceSblAuthMgrGetSelfInfo						0x006441E0
#define addr_sceSblAuthMgrSmStart							0x0063FEE0
#define addr_sceSblAuthMgrVerifyHeader						0x00643A00
#define addr_sbl_drv_msg_mtx								0x02646CB0
#define addr_gpu_va_page_list								0x02646CA8
#define addr_mini_syscore_self_binary						0x01579DF8
#define addr_sceSblAuthMgrVerifyHeaderHook1					0x00645026
#define addr_sceSblAuthMgrVerifyHeaderHook2					0x00645D09
#define addr_SceSblAuthMgrIsLoadable2Hook					0x0064488E
#define addr_SceSblAuthMgrSmLoadSelfSegment_Mailbox			0x0064232D
#define addr_SceSblAuthMgrSmLoadSelfBlock_Mailbox			0x00642F68
#define addr_sceSblAuthMgrIsLoadable__sceSblACMgrGetPathId	0x0064473C

/* Fake Pkgs */
#define addr_sbl_keymgr_buf_gva								0x0264C808
#define addr_sbl_keymgr_buf_va								0x0264C000
#define addr_sbl_keymgr_key_slots							0x02648238
#define addr_sbl_keymgr_key_rbtree							0x02648248
#define addr_sbl_pfs_sx										0x0264DB40
#define addr_fpu_ctx										0x026541C0
#define addr_fpu_kern_enter									0x002196D0
#define addr_fpu_kern_leave									0x00219790
#define addr_Sha256Hmac										0x00445060
#define addr_sceSblDriverSendMsg							0x0061CED0
#define addr_sceSblPfsSetKeys								0x006252D0
#define addr_RsaesPkcs1v15Dec2048CRT						0x004628B0
#define addr_AesCbcCfb128Encrypt							0x001FF2D0
#define addr_AesCbcCfb128Decrypt							0x001FF500
#define addr_sceSblKeymgrSetKeyForPfs						0x0061F690
#define addr_sceSblKeymgrClearKey							0x0061F9D0
#define addr_sceSblKeymgrSetKeyStorage						0x00624970

#define addr_SceSblDriverSendMsgHook						0x00624A15
#define addr_SceSblPfsSetKeysHook							0x006C3EF9
#define addr_NpdrmDecryptIsolatedRifHook					0x0064E070
#define addr_NpdrmDecryptRifNewHook							0x0064EE3E
#define addr_SceSblKeymgrInvalidateKeySxXlockHook			0x0062084D

/* Library Replacement */
#define addr_load_prx					0x021DF60

/* ShellCore Patches */
#define addr_sceKernelIsGenuineCEX1		0x0016EAA4
#define addr_sceKernelIsGenuineCEX2		0x008621D4
#define addr_sceKernelIsGenuineCEX3		0x008AFBC2
#define addr_sceKernelIsGenuineCEX4		0x00A27BD4

#define addr_sceKernelIsAssistMode1		0x0016EAD2
#define addr_sceKernelIsAssistMode2		0x00862202
#define addr_sceKernelIsAssistMode3		0x00249F7B
#define addr_sceKernelIsAssistMode4		0x00A27C02

#define addr_enableFpkg					0x003D7AFF
#define addr_fakeText					0x00FD3211
#define addr_mountDataIntoSandbox		0x0032079B
#define addr_disableCoreDumps			0x002EFC1B
#define addr_disableUpdateChecks		0x3C8540

#define addr_disablePkgPatchCheck1		0x3C5EA7
#define addr_disablePkgPatchCheck2		0x138E90
#define addr_disablePkgPatchCheck3		0x13097F

/* ShellUI Patches */
#define sceKernelGetDebugMenuModeForRcmgr		0x0001D1C0
#define sceKernelGetUtokenStoreModeForRcmgr		0x0001D520

#endif