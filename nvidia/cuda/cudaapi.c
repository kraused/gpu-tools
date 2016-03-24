
#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "cudaapi.h"

void Nvcu_Default_Return_Handler(const char *caller,
                                 const char *callee,
                                 CUresult err,
                                 const char *errname,
                                 const char *errstr)
{
	if (UNLIKELY(CUDA_SUCCESS != err)) {
		fprintf(stderr, "%s: %s() returned %d: %s (%s)\n", caller, callee, (int )err, errname, errstr);
		fflush (stderr);
		_exit(1);
	}
}

void Nvcu_Debug_Return_Handler(const char *caller,
                               const char *callee,
                               CUresult err,
                               const char *errname,
                               const char *errstr)
{
	fprintf(stderr, "%s: %s() returned %d: %s (%s)\n", caller, callee, (int )err, errname, errstr);
	fflush (stderr);
	if (UNLIKELY(CUDA_SUCCESS != err)) {
		_exit(1);
	}
}

Nvcu_Return_Handling_Function nvcu_return_handler = Nvcu_Default_Return_Handler;

/* Wrapper around CUDA driver API library calls.
 *
 * Generated with python2 wrap-cuda.py --definitions.
 */

void Nvcu_GetErrorName(CUresult a0, const char** a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGetErrorName(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGetErrorName", "cuGetErrorName", err, errName, errString);
}

void Nvcu_GetErrorString(CUresult a0, const char** a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGetErrorString(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGetErrorString", "cuGetErrorString", err, errName, errString);
}

void Nvcu_Init(unsigned int a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuInit(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuInit", "cuInit", err, errName, errString);
}

void Nvcu_DriverGetVersion(int* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDriverGetVersion(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDriverGetVersion", "cuDriverGetVersion", err, errName, errString);
}

void Nvcu_DeviceGet(CUdevice* a0, int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGet(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGet", "cuDeviceGet", err, errName, errString);
}

void Nvcu_DeviceGetAttribute(int* a0, CUdevice_attribute a1, CUdevice a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGetAttribute(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGetAttribute", "cuDeviceGetAttribute", err, errName, errString);
}

void Nvcu_DeviceGetCount(int* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGetCount(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGetCount", "cuDeviceGetCount", err, errName, errString);
}

void Nvcu_DeviceGetName(char* a0, int a1, CUdevice a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGetName(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGetName", "cuDeviceGetName", err, errName, errString);
}

void Nvcu_DeviceTotalMem(size_t* a0, CUdevice a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceTotalMem(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceTotalMem", "cuDeviceTotalMem", err, errName, errString);
}

void Nvcu_DevicePrimaryCtxGetState(CUdevice a0, unsigned int* a1, int* a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDevicePrimaryCtxGetState(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDevicePrimaryCtxGetState", "cuDevicePrimaryCtxGetState", err, errName, errString);
}

void Nvcu_DevicePrimaryCtxRelease(CUdevice a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDevicePrimaryCtxRelease(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDevicePrimaryCtxRelease", "cuDevicePrimaryCtxRelease", err, errName, errString);
}

void Nvcu_DevicePrimaryCtxReset(CUdevice a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDevicePrimaryCtxReset(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDevicePrimaryCtxReset", "cuDevicePrimaryCtxReset", err, errName, errString);
}

void Nvcu_DevicePrimaryCtxRetain(CUcontext* a0, CUdevice a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDevicePrimaryCtxRetain(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDevicePrimaryCtxRetain", "cuDevicePrimaryCtxRetain", err, errName, errString);
}

void Nvcu_DevicePrimaryCtxSetFlags(CUdevice a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDevicePrimaryCtxSetFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDevicePrimaryCtxSetFlags", "cuDevicePrimaryCtxSetFlags", err, errName, errString);
}

void Nvcu_CtxCreate(CUcontext* a0, unsigned int a1, CUdevice a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxCreate(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxCreate", "cuCtxCreate", err, errName, errString);
}

void Nvcu_CtxDestroy(CUcontext a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxDestroy", "cuCtxDestroy", err, errName, errString);
}

void Nvcu_CtxGetApiVersion(CUcontext a0, unsigned int* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetApiVersion(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetApiVersion", "cuCtxGetApiVersion", err, errName, errString);
}

void Nvcu_CtxGetCacheConfig(CUfunc_cache* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetCacheConfig(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetCacheConfig", "cuCtxGetCacheConfig", err, errName, errString);
}

void Nvcu_CtxGetCurrent(CUcontext* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetCurrent(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetCurrent", "cuCtxGetCurrent", err, errName, errString);
}

void Nvcu_CtxGetDevice(CUdevice* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetDevice(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetDevice", "cuCtxGetDevice", err, errName, errString);
}

void Nvcu_CtxGetFlags(unsigned int* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetFlags(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetFlags", "cuCtxGetFlags", err, errName, errString);
}

void Nvcu_CtxGetLimit(size_t* a0, CUlimit a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetLimit(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetLimit", "cuCtxGetLimit", err, errName, errString);
}

void Nvcu_CtxGetSharedMemConfig(CUsharedconfig* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetSharedMemConfig(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetSharedMemConfig", "cuCtxGetSharedMemConfig", err, errName, errString);
}

void Nvcu_CtxGetStreamPriorityRange(int* a0, int* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxGetStreamPriorityRange(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxGetStreamPriorityRange", "cuCtxGetStreamPriorityRange", err, errName, errString);
}

void Nvcu_CtxPopCurrent(CUcontext* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxPopCurrent(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxPopCurrent", "cuCtxPopCurrent", err, errName, errString);
}

void Nvcu_CtxPushCurrent(CUcontext a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxPushCurrent(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxPushCurrent", "cuCtxPushCurrent", err, errName, errString);
}

void Nvcu_CtxSetCacheConfig(CUfunc_cache a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxSetCacheConfig(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxSetCacheConfig", "cuCtxSetCacheConfig", err, errName, errString);
}

void Nvcu_CtxSetCurrent(CUcontext a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxSetCurrent(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxSetCurrent", "cuCtxSetCurrent", err, errName, errString);
}

void Nvcu_CtxSetLimit(CUlimit a0, size_t a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxSetLimit(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxSetLimit", "cuCtxSetLimit", err, errName, errString);
}

void Nvcu_CtxSetSharedMemConfig(CUsharedconfig a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxSetSharedMemConfig(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxSetSharedMemConfig", "cuCtxSetSharedMemConfig", err, errName, errString);
}

void Nvcu_CtxSynchronize()
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxSynchronize();
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxSynchronize", "cuCtxSynchronize", err, errName, errString);
}

void Nvcu_LinkAddData(CUlinkState a0, CUjitInputType a1, void* a2, size_t a3, const char* a4, unsigned int a5, CUjit_option* a6, void** a7)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLinkAddData(a0, a1, a2, a3, a4, a5, a6, a7);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLinkAddData", "cuLinkAddData", err, errName, errString);
}

void Nvcu_LinkAddFile(CUlinkState a0, CUjitInputType a1, const char* a2, unsigned int a3, CUjit_option* a4, void** a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLinkAddFile(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLinkAddFile", "cuLinkAddFile", err, errName, errString);
}

void Nvcu_LinkComplete(CUlinkState a0, void** a1, size_t* a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLinkComplete(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLinkComplete", "cuLinkComplete", err, errName, errString);
}

void Nvcu_LinkCreate(unsigned int a0, CUjit_option* a1, void** a2, CUlinkState* a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLinkCreate(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLinkCreate", "cuLinkCreate", err, errName, errString);
}

void Nvcu_LinkDestroy(CUlinkState a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLinkDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLinkDestroy", "cuLinkDestroy", err, errName, errString);
}

void Nvcu_ModuleGetFunction(CUfunction* a0, CUmodule a1, const char* a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleGetFunction(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleGetFunction", "cuModuleGetFunction", err, errName, errString);
}

void Nvcu_ModuleGetGlobal(CUdeviceptr* a0, size_t* a1, CUmodule a2, const char* a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleGetGlobal(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleGetGlobal", "cuModuleGetGlobal", err, errName, errString);
}

void Nvcu_ModuleGetSurfRef(CUsurfref* a0, CUmodule a1, const char* a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleGetSurfRef(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleGetSurfRef", "cuModuleGetSurfRef", err, errName, errString);
}

void Nvcu_ModuleGetTexRef(CUtexref* a0, CUmodule a1, const char* a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleGetTexRef(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleGetTexRef", "cuModuleGetTexRef", err, errName, errString);
}

void Nvcu_ModuleLoad(CUmodule* a0, const char* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleLoad(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleLoad", "cuModuleLoad", err, errName, errString);
}

void Nvcu_ModuleLoadData(CUmodule* a0, const void* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleLoadData(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleLoadData", "cuModuleLoadData", err, errName, errString);
}

void Nvcu_ModuleLoadDataEx(CUmodule* a0, const void* a1, unsigned int a2, CUjit_option* a3, void** a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleLoadDataEx(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleLoadDataEx", "cuModuleLoadDataEx", err, errName, errString);
}

void Nvcu_ModuleLoadFatBinary(CUmodule* a0, const void* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleLoadFatBinary(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleLoadFatBinary", "cuModuleLoadFatBinary", err, errName, errString);
}

void Nvcu_ModuleUnload(CUmodule a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuModuleUnload(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuModuleUnload", "cuModuleUnload", err, errName, errString);
}

void Nvcu_Array3DCreate(CUarray* a0, const CUDA_ARRAY3D_DESCRIPTOR* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuArray3DCreate(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuArray3DCreate", "cuArray3DCreate", err, errName, errString);
}

void Nvcu_Array3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR* a0, CUarray a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuArray3DGetDescriptor(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuArray3DGetDescriptor", "cuArray3DGetDescriptor", err, errName, errString);
}

void Nvcu_ArrayCreate(CUarray* a0, const CUDA_ARRAY_DESCRIPTOR* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuArrayCreate(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuArrayCreate", "cuArrayCreate", err, errName, errString);
}

void Nvcu_ArrayDestroy(CUarray a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuArrayDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuArrayDestroy", "cuArrayDestroy", err, errName, errString);
}

void Nvcu_ArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR* a0, CUarray a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuArrayGetDescriptor(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuArrayGetDescriptor", "cuArrayGetDescriptor", err, errName, errString);
}

void Nvcu_DeviceGetByPCIBusId(CUdevice* a0, const char* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGetByPCIBusId(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGetByPCIBusId", "cuDeviceGetByPCIBusId", err, errName, errString);
}

void Nvcu_DeviceGetPCIBusId(char* a0, int a1, CUdevice a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceGetPCIBusId(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceGetPCIBusId", "cuDeviceGetPCIBusId", err, errName, errString);
}

void Nvcu_IpcCloseMemHandle(CUdeviceptr a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuIpcCloseMemHandle(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuIpcCloseMemHandle", "cuIpcCloseMemHandle", err, errName, errString);
}

void Nvcu_IpcGetEventHandle(CUipcEventHandle* a0, CUevent a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuIpcGetEventHandle(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuIpcGetEventHandle", "cuIpcGetEventHandle", err, errName, errString);
}

void Nvcu_IpcGetMemHandle(CUipcMemHandle* a0, CUdeviceptr a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuIpcGetMemHandle(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuIpcGetMemHandle", "cuIpcGetMemHandle", err, errName, errString);
}

void Nvcu_IpcOpenEventHandle(CUevent* a0, CUipcEventHandle a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuIpcOpenEventHandle(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuIpcOpenEventHandle", "cuIpcOpenEventHandle", err, errName, errString);
}

void Nvcu_IpcOpenMemHandle(CUdeviceptr* a0, CUipcMemHandle a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuIpcOpenMemHandle(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuIpcOpenMemHandle", "cuIpcOpenMemHandle", err, errName, errString);
}

void Nvcu_MemAlloc(CUdeviceptr* a0, size_t a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemAlloc(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemAlloc", "cuMemAlloc", err, errName, errString);
}

void Nvcu_MemAllocHost(void** a0, size_t a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemAllocHost(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemAllocHost", "cuMemAllocHost", err, errName, errString);
}

void Nvcu_MemAllocManaged(CUdeviceptr* a0, size_t a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemAllocManaged(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemAllocManaged", "cuMemAllocManaged", err, errName, errString);
}

void Nvcu_MemAllocPitch(CUdeviceptr* a0, size_t* a1, size_t a2, size_t a3, unsigned int a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemAllocPitch(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemAllocPitch", "cuMemAllocPitch", err, errName, errString);
}

void Nvcu_MemFree(CUdeviceptr a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemFree(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemFree", "cuMemFree", err, errName, errString);
}

void Nvcu_MemFreeHost(void* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemFreeHost(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemFreeHost", "cuMemFreeHost", err, errName, errString);
}

void Nvcu_MemGetAddressRange(CUdeviceptr* a0, size_t* a1, CUdeviceptr a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemGetAddressRange(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemGetAddressRange", "cuMemGetAddressRange", err, errName, errString);
}

void Nvcu_MemGetInfo(size_t* a0, size_t* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemGetInfo(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemGetInfo", "cuMemGetInfo", err, errName, errString);
}

void Nvcu_MemHostAlloc(void** a0, size_t a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemHostAlloc(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemHostAlloc", "cuMemHostAlloc", err, errName, errString);
}

void Nvcu_MemHostGetDevicePointer(CUdeviceptr* a0, void* a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemHostGetDevicePointer(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemHostGetDevicePointer", "cuMemHostGetDevicePointer", err, errName, errString);
}

void Nvcu_MemHostGetFlags(unsigned int* a0, void* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemHostGetFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemHostGetFlags", "cuMemHostGetFlags", err, errName, errString);
}

void Nvcu_MemHostRegister(void* a0, size_t a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemHostRegister(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemHostRegister", "cuMemHostRegister", err, errName, errString);
}

void Nvcu_MemHostUnregister(void* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemHostUnregister(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemHostUnregister", "cuMemHostUnregister", err, errName, errString);
}

void Nvcu_Memcpy(CUdeviceptr a0, CUdeviceptr a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy", "cuMemcpy", err, errName, errString);
}

void Nvcu_Memcpy2D(const CUDA_MEMCPY2D* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy2D(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy2D", "cuMemcpy2D", err, errName, errString);
}

void Nvcu_Memcpy2DAsync(const CUDA_MEMCPY2D* a0, CUstream a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy2DAsync(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy2DAsync", "cuMemcpy2DAsync", err, errName, errString);
}

void Nvcu_Memcpy2DUnaligned(const CUDA_MEMCPY2D* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy2DUnaligned(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy2DUnaligned", "cuMemcpy2DUnaligned", err, errName, errString);
}

void Nvcu_Memcpy3D(const CUDA_MEMCPY3D* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy3D(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy3D", "cuMemcpy3D", err, errName, errString);
}

void Nvcu_Memcpy3DAsync(const CUDA_MEMCPY3D* a0, CUstream a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy3DAsync(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy3DAsync", "cuMemcpy3DAsync", err, errName, errString);
}

void Nvcu_Memcpy3DPeer(const CUDA_MEMCPY3D_PEER* a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy3DPeer(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy3DPeer", "cuMemcpy3DPeer", err, errName, errString);
}

void Nvcu_Memcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER* a0, CUstream a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpy3DPeerAsync(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpy3DPeerAsync", "cuMemcpy3DPeerAsync", err, errName, errString);
}

void Nvcu_MemcpyAsync(CUdeviceptr a0, CUdeviceptr a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyAsync(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyAsync", "cuMemcpyAsync", err, errName, errString);
}

void Nvcu_MemcpyAtoA(CUarray a0, size_t a1, CUarray a2, size_t a3, size_t a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyAtoA(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyAtoA", "cuMemcpyAtoA", err, errName, errString);
}

void Nvcu_MemcpyAtoD(CUdeviceptr a0, CUarray a1, size_t a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyAtoD(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyAtoD", "cuMemcpyAtoD", err, errName, errString);
}

void Nvcu_MemcpyAtoH(void* a0, CUarray a1, size_t a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyAtoH(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyAtoH", "cuMemcpyAtoH", err, errName, errString);
}

void Nvcu_MemcpyAtoHAsync(void* a0, CUarray a1, size_t a2, size_t a3, CUstream a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyAtoHAsync(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyAtoHAsync", "cuMemcpyAtoHAsync", err, errName, errString);
}

void Nvcu_MemcpyDtoA(CUarray a0, size_t a1, CUdeviceptr a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyDtoA(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyDtoA", "cuMemcpyDtoA", err, errName, errString);
}

void Nvcu_MemcpyDtoD(CUdeviceptr a0, CUdeviceptr a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyDtoD(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyDtoD", "cuMemcpyDtoD", err, errName, errString);
}

void Nvcu_MemcpyDtoDAsync(CUdeviceptr a0, CUdeviceptr a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyDtoDAsync(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyDtoDAsync", "cuMemcpyDtoDAsync", err, errName, errString);
}

void Nvcu_MemcpyDtoH(void* a0, CUdeviceptr a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyDtoH(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyDtoH", "cuMemcpyDtoH", err, errName, errString);
}

void Nvcu_MemcpyDtoHAsync(void* a0, CUdeviceptr a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyDtoHAsync(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyDtoHAsync", "cuMemcpyDtoHAsync", err, errName, errString);
}

void Nvcu_MemcpyHtoA(CUarray a0, size_t a1, const void* a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyHtoA(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyHtoA", "cuMemcpyHtoA", err, errName, errString);
}

void Nvcu_MemcpyHtoAAsync(CUarray a0, size_t a1, const void* a2, size_t a3, CUstream a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyHtoAAsync(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyHtoAAsync", "cuMemcpyHtoAAsync", err, errName, errString);
}

void Nvcu_MemcpyHtoD(CUdeviceptr a0, const void* a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyHtoD(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyHtoD", "cuMemcpyHtoD", err, errName, errString);
}

void Nvcu_MemcpyHtoDAsync(CUdeviceptr a0, const void* a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyHtoDAsync(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyHtoDAsync", "cuMemcpyHtoDAsync", err, errName, errString);
}

void Nvcu_MemcpyPeer(CUdeviceptr a0, CUcontext a1, CUdeviceptr a2, CUcontext a3, size_t a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyPeer(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyPeer", "cuMemcpyPeer", err, errName, errString);
}

void Nvcu_MemcpyPeerAsync(CUdeviceptr a0, CUcontext a1, CUdeviceptr a2, CUcontext a3, size_t a4, CUstream a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemcpyPeerAsync(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemcpyPeerAsync", "cuMemcpyPeerAsync", err, errName, errString);
}

void Nvcu_MemsetD16(CUdeviceptr a0, unsigned short a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD16(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD16", "cuMemsetD16", err, errName, errString);
}

void Nvcu_MemsetD16Async(CUdeviceptr a0, unsigned short a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD16Async(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD16Async", "cuMemsetD16Async", err, errName, errString);
}

void Nvcu_MemsetD2D16(CUdeviceptr a0, size_t a1, unsigned short a2, size_t a3, size_t a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D16(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D16", "cuMemsetD2D16", err, errName, errString);
}

void Nvcu_MemsetD2D16Async(CUdeviceptr a0, size_t a1, unsigned short a2, size_t a3, size_t a4, CUstream a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D16Async(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D16Async", "cuMemsetD2D16Async", err, errName, errString);
}

void Nvcu_MemsetD2D32(CUdeviceptr a0, size_t a1, unsigned int a2, size_t a3, size_t a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D32(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D32", "cuMemsetD2D32", err, errName, errString);
}

void Nvcu_MemsetD2D32Async(CUdeviceptr a0, size_t a1, unsigned int a2, size_t a3, size_t a4, CUstream a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D32Async(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D32Async", "cuMemsetD2D32Async", err, errName, errString);
}

void Nvcu_MemsetD2D8(CUdeviceptr a0, size_t a1, unsigned char a2, size_t a3, size_t a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D8(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D8", "cuMemsetD2D8", err, errName, errString);
}

void Nvcu_MemsetD2D8Async(CUdeviceptr a0, size_t a1, unsigned char a2, size_t a3, size_t a4, CUstream a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD2D8Async(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD2D8Async", "cuMemsetD2D8Async", err, errName, errString);
}

void Nvcu_MemsetD32(CUdeviceptr a0, unsigned int a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD32(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD32", "cuMemsetD32", err, errName, errString);
}

void Nvcu_MemsetD32Async(CUdeviceptr a0, unsigned int a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD32Async(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD32Async", "cuMemsetD32Async", err, errName, errString);
}

void Nvcu_MemsetD8(CUdeviceptr a0, unsigned char a1, size_t a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD8(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD8", "cuMemsetD8", err, errName, errString);
}

void Nvcu_MemsetD8Async(CUdeviceptr a0, unsigned char a1, size_t a2, CUstream a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMemsetD8Async(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMemsetD8Async", "cuMemsetD8Async", err, errName, errString);
}

void Nvcu_MipmappedArrayCreate(CUmipmappedArray* a0, const CUDA_ARRAY3D_DESCRIPTOR* a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMipmappedArrayCreate(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMipmappedArrayCreate", "cuMipmappedArrayCreate", err, errName, errString);
}

void Nvcu_MipmappedArrayDestroy(CUmipmappedArray a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMipmappedArrayDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMipmappedArrayDestroy", "cuMipmappedArrayDestroy", err, errName, errString);
}

void Nvcu_MipmappedArrayGetLevel(CUarray* a0, CUmipmappedArray a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuMipmappedArrayGetLevel(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuMipmappedArrayGetLevel", "cuMipmappedArrayGetLevel", err, errName, errString);
}

void Nvcu_PointerGetAttribute(void* a0, CUpointer_attribute a1, CUdeviceptr a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuPointerGetAttribute(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuPointerGetAttribute", "cuPointerGetAttribute", err, errName, errString);
}

void Nvcu_PointerGetAttributes(unsigned int a0, CUpointer_attribute* a1, void** a2, CUdeviceptr a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuPointerGetAttributes(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuPointerGetAttributes", "cuPointerGetAttributes", err, errName, errString);
}

void Nvcu_PointerSetAttribute(const void* a0, CUpointer_attribute a1, CUdeviceptr a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuPointerSetAttribute(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuPointerSetAttribute", "cuPointerSetAttribute", err, errName, errString);
}

void Nvcu_StreamAddCallback(CUstream a0, CUstreamCallback a1, void* a2, unsigned int a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamAddCallback(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamAddCallback", "cuStreamAddCallback", err, errName, errString);
}

void Nvcu_StreamAttachMemAsync(CUstream a0, CUdeviceptr a1, size_t a2, unsigned int a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamAttachMemAsync(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamAttachMemAsync", "cuStreamAttachMemAsync", err, errName, errString);
}

void Nvcu_StreamCreate(CUstream* a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamCreate(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamCreate", "cuStreamCreate", err, errName, errString);
}

void Nvcu_StreamCreateWithPriority(CUstream* a0, unsigned int a1, int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamCreateWithPriority(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamCreateWithPriority", "cuStreamCreateWithPriority", err, errName, errString);
}

void Nvcu_StreamDestroy(CUstream a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamDestroy", "cuStreamDestroy", err, errName, errString);
}

void Nvcu_StreamGetFlags(CUstream a0, unsigned int* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamGetFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamGetFlags", "cuStreamGetFlags", err, errName, errString);
}

void Nvcu_StreamGetPriority(CUstream a0, int* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamGetPriority(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamGetPriority", "cuStreamGetPriority", err, errName, errString);
}

void Nvcu_StreamQuery(CUstream a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamQuery(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamQuery", "cuStreamQuery", err, errName, errString);
}

void Nvcu_StreamSynchronize(CUstream a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamSynchronize(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamSynchronize", "cuStreamSynchronize", err, errName, errString);
}

void Nvcu_StreamWaitEvent(CUstream a0, CUevent a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuStreamWaitEvent(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuStreamWaitEvent", "cuStreamWaitEvent", err, errName, errString);
}

void Nvcu_EventCreate(CUevent* a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventCreate(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventCreate", "cuEventCreate", err, errName, errString);
}

void Nvcu_EventDestroy(CUevent a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventDestroy", "cuEventDestroy", err, errName, errString);
}

void Nvcu_EventElapsedTime(float* a0, CUevent a1, CUevent a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventElapsedTime(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventElapsedTime", "cuEventElapsedTime", err, errName, errString);
}

void Nvcu_EventQuery(CUevent a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventQuery(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventQuery", "cuEventQuery", err, errName, errString);
}

void Nvcu_EventRecord(CUevent a0, CUstream a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventRecord(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventRecord", "cuEventRecord", err, errName, errString);
}

void Nvcu_EventSynchronize(CUevent a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuEventSynchronize(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuEventSynchronize", "cuEventSynchronize", err, errName, errString);
}

void Nvcu_FuncGetAttribute(int* a0, CUfunction_attribute a1, CUfunction a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuFuncGetAttribute(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuFuncGetAttribute", "cuFuncGetAttribute", err, errName, errString);
}

void Nvcu_FuncSetCacheConfig(CUfunction a0, CUfunc_cache a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuFuncSetCacheConfig(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuFuncSetCacheConfig", "cuFuncSetCacheConfig", err, errName, errString);
}

void Nvcu_FuncSetSharedMemConfig(CUfunction a0, CUsharedconfig a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuFuncSetSharedMemConfig(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuFuncSetSharedMemConfig", "cuFuncSetSharedMemConfig", err, errName, errString);
}

void Nvcu_LaunchKernel(CUfunction a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, CUstream a8, void** a9, void** a10)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuLaunchKernel(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuLaunchKernel", "cuLaunchKernel", err, errName, errString);
}

void Nvcu_OccupancyMaxActiveBlocksPerMultiprocessor(int* a0, CUfunction a1, int a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuOccupancyMaxActiveBlocksPerMultiprocessor(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuOccupancyMaxActiveBlocksPerMultiprocessor", "cuOccupancyMaxActiveBlocksPerMultiprocessor", err, errName, errString);
}

void Nvcu_OccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int* a0, CUfunction a1, int a2, size_t a3, unsigned int a4)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(a0, a1, a2, a3, a4);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags", "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags", err, errName, errString);
}

void Nvcu_OccupancyMaxPotentialBlockSize(int* a0, int* a1, CUfunction a2, CUoccupancyB2DSize a3, size_t a4, int a5)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuOccupancyMaxPotentialBlockSize(a0, a1, a2, a3, a4, a5);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuOccupancyMaxPotentialBlockSize", "cuOccupancyMaxPotentialBlockSize", err, errName, errString);
}

void Nvcu_OccupancyMaxPotentialBlockSizeWithFlags(int* a0, int* a1, CUfunction a2, CUoccupancyB2DSize a3, size_t a4, int a5, unsigned int a6)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuOccupancyMaxPotentialBlockSizeWithFlags(a0, a1, a2, a3, a4, a5, a6);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuOccupancyMaxPotentialBlockSizeWithFlags", "cuOccupancyMaxPotentialBlockSizeWithFlags", err, errName, errString);
}

void Nvcu_TexRefGetAddress(CUdeviceptr* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetAddress(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetAddress", "cuTexRefGetAddress", err, errName, errString);
}

void Nvcu_TexRefGetAddressMode(CUaddress_mode* a0, CUtexref a1, int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetAddressMode(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetAddressMode", "cuTexRefGetAddressMode", err, errName, errString);
}

void Nvcu_TexRefGetArray(CUarray* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetArray(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetArray", "cuTexRefGetArray", err, errName, errString);
}

void Nvcu_TexRefGetFilterMode(CUfilter_mode* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetFilterMode(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetFilterMode", "cuTexRefGetFilterMode", err, errName, errString);
}

void Nvcu_TexRefGetFlags(unsigned int* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetFlags", "cuTexRefGetFlags", err, errName, errString);
}

void Nvcu_TexRefGetFormat(CUarray_format* a0, int* a1, CUtexref a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetFormat(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetFormat", "cuTexRefGetFormat", err, errName, errString);
}

void Nvcu_TexRefGetMaxAnisotropy(int* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetMaxAnisotropy(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetMaxAnisotropy", "cuTexRefGetMaxAnisotropy", err, errName, errString);
}

void Nvcu_TexRefGetMipmapFilterMode(CUfilter_mode* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetMipmapFilterMode(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetMipmapFilterMode", "cuTexRefGetMipmapFilterMode", err, errName, errString);
}

void Nvcu_TexRefGetMipmapLevelBias(float* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetMipmapLevelBias(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetMipmapLevelBias", "cuTexRefGetMipmapLevelBias", err, errName, errString);
}

void Nvcu_TexRefGetMipmapLevelClamp(float* a0, float* a1, CUtexref a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetMipmapLevelClamp(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetMipmapLevelClamp", "cuTexRefGetMipmapLevelClamp", err, errName, errString);
}

void Nvcu_TexRefGetMipmappedArray(CUmipmappedArray* a0, CUtexref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefGetMipmappedArray(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefGetMipmappedArray", "cuTexRefGetMipmappedArray", err, errName, errString);
}

void Nvcu_TexRefSetAddress(size_t* a0, CUtexref a1, CUdeviceptr a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetAddress(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetAddress", "cuTexRefSetAddress", err, errName, errString);
}

void Nvcu_TexRefSetAddress2D(CUtexref a0, const CUDA_ARRAY_DESCRIPTOR* a1, CUdeviceptr a2, size_t a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetAddress2D(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetAddress2D", "cuTexRefSetAddress2D", err, errName, errString);
}

void Nvcu_TexRefSetAddressMode(CUtexref a0, int a1, CUaddress_mode a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetAddressMode(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetAddressMode", "cuTexRefSetAddressMode", err, errName, errString);
}

void Nvcu_TexRefSetArray(CUtexref a0, CUarray a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetArray(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetArray", "cuTexRefSetArray", err, errName, errString);
}

void Nvcu_TexRefSetFilterMode(CUtexref a0, CUfilter_mode a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetFilterMode(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetFilterMode", "cuTexRefSetFilterMode", err, errName, errString);
}

void Nvcu_TexRefSetFlags(CUtexref a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetFlags", "cuTexRefSetFlags", err, errName, errString);
}

void Nvcu_TexRefSetFormat(CUtexref a0, CUarray_format a1, int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetFormat(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetFormat", "cuTexRefSetFormat", err, errName, errString);
}

void Nvcu_TexRefSetMaxAnisotropy(CUtexref a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetMaxAnisotropy(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetMaxAnisotropy", "cuTexRefSetMaxAnisotropy", err, errName, errString);
}

void Nvcu_TexRefSetMipmapFilterMode(CUtexref a0, CUfilter_mode a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetMipmapFilterMode(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetMipmapFilterMode", "cuTexRefSetMipmapFilterMode", err, errName, errString);
}

void Nvcu_TexRefSetMipmapLevelBias(CUtexref a0, float a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetMipmapLevelBias(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetMipmapLevelBias", "cuTexRefSetMipmapLevelBias", err, errName, errString);
}

void Nvcu_TexRefSetMipmapLevelClamp(CUtexref a0, float a1, float a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetMipmapLevelClamp(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetMipmapLevelClamp", "cuTexRefSetMipmapLevelClamp", err, errName, errString);
}

void Nvcu_TexRefSetMipmappedArray(CUtexref a0, CUmipmappedArray a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexRefSetMipmappedArray(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexRefSetMipmappedArray", "cuTexRefSetMipmappedArray", err, errName, errString);
}

void Nvcu_SurfRefGetArray(CUarray* a0, CUsurfref a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuSurfRefGetArray(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuSurfRefGetArray", "cuSurfRefGetArray", err, errName, errString);
}

void Nvcu_SurfRefSetArray(CUsurfref a0, CUarray a1, unsigned int a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuSurfRefSetArray(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuSurfRefSetArray", "cuSurfRefSetArray", err, errName, errString);
}

void Nvcu_TexObjectCreate(CUtexObject* a0, const CUDA_RESOURCE_DESC* a1, const CUDA_TEXTURE_DESC* a2, const CUDA_RESOURCE_VIEW_DESC* a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexObjectCreate(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexObjectCreate", "cuTexObjectCreate", err, errName, errString);
}

void Nvcu_TexObjectDestroy(CUtexObject a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexObjectDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexObjectDestroy", "cuTexObjectDestroy", err, errName, errString);
}

void Nvcu_TexObjectGetResourceDesc(CUDA_RESOURCE_DESC* a0, CUtexObject a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexObjectGetResourceDesc(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexObjectGetResourceDesc", "cuTexObjectGetResourceDesc", err, errName, errString);
}

void Nvcu_TexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC* a0, CUtexObject a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexObjectGetResourceViewDesc(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexObjectGetResourceViewDesc", "cuTexObjectGetResourceViewDesc", err, errName, errString);
}

void Nvcu_TexObjectGetTextureDesc(CUDA_TEXTURE_DESC* a0, CUtexObject a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuTexObjectGetTextureDesc(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuTexObjectGetTextureDesc", "cuTexObjectGetTextureDesc", err, errName, errString);
}

void Nvcu_SurfObjectCreate(CUsurfObject* a0, const CUDA_RESOURCE_DESC* a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuSurfObjectCreate(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuSurfObjectCreate", "cuSurfObjectCreate", err, errName, errString);
}

void Nvcu_SurfObjectDestroy(CUsurfObject a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuSurfObjectDestroy(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuSurfObjectDestroy", "cuSurfObjectDestroy", err, errName, errString);
}

void Nvcu_SurfObjectGetResourceDesc(CUDA_RESOURCE_DESC* a0, CUsurfObject a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuSurfObjectGetResourceDesc(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuSurfObjectGetResourceDesc", "cuSurfObjectGetResourceDesc", err, errName, errString);
}

void Nvcu_CtxDisablePeerAccess(CUcontext a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxDisablePeerAccess(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxDisablePeerAccess", "cuCtxDisablePeerAccess", err, errName, errString);
}

void Nvcu_CtxEnablePeerAccess(CUcontext a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuCtxEnablePeerAccess(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuCtxEnablePeerAccess", "cuCtxEnablePeerAccess", err, errName, errString);
}

void Nvcu_DeviceCanAccessPeer(int* a0, CUdevice a1, CUdevice a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuDeviceCanAccessPeer(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuDeviceCanAccessPeer", "cuDeviceCanAccessPeer", err, errName, errString);
}

void Nvcu_GraphicsMapResources(unsigned int a0, CUgraphicsResource* a1, CUstream a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsMapResources(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsMapResources", "cuGraphicsMapResources", err, errName, errString);
}

void Nvcu_GraphicsResourceGetMappedMipmappedArray(CUmipmappedArray* a0, CUgraphicsResource a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsResourceGetMappedMipmappedArray(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsResourceGetMappedMipmappedArray", "cuGraphicsResourceGetMappedMipmappedArray", err, errName, errString);
}

void Nvcu_GraphicsResourceGetMappedPointer(CUdeviceptr* a0, size_t* a1, CUgraphicsResource a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsResourceGetMappedPointer(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsResourceGetMappedPointer", "cuGraphicsResourceGetMappedPointer", err, errName, errString);
}

void Nvcu_GraphicsResourceSetMapFlags(CUgraphicsResource a0, unsigned int a1)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsResourceSetMapFlags(a0, a1);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsResourceSetMapFlags", "cuGraphicsResourceSetMapFlags", err, errName, errString);
}

void Nvcu_GraphicsSubResourceGetMappedArray(CUarray* a0, CUgraphicsResource a1, unsigned int a2, unsigned int a3)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsSubResourceGetMappedArray(a0, a1, a2, a3);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsSubResourceGetMappedArray", "cuGraphicsSubResourceGetMappedArray", err, errName, errString);
}

void Nvcu_GraphicsUnmapResources(unsigned int a0, CUgraphicsResource* a1, CUstream a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsUnmapResources(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsUnmapResources", "cuGraphicsUnmapResources", err, errName, errString);
}

void Nvcu_GraphicsUnregisterResource(CUgraphicsResource a0)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuGraphicsUnregisterResource(a0);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuGraphicsUnregisterResource", "cuGraphicsUnregisterResource", err, errName, errString);
}

void Nvcu_ProfilerInitialize(const char* a0, const char* a1, CUoutput_mode a2)
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuProfilerInitialize(a0, a1, a2);
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuProfilerInitialize", "cuProfilerInitialize", err, errName, errString);
}

void Nvcu_ProfilerStart()
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuProfilerStart();
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuProfilerStart", "cuProfilerStart", err, errName, errString);
}

void Nvcu_ProfilerStop()
{
	CUresult err;
	const char *errName;
	const char *errString;
	err = cuProfilerStop();
	cuGetErrorName(err, &errName); /* Ignore error. */
	cuGetErrorString(err, &errString); /* Ignore error. */
	nvcu_return_handler("cuProfilerStop", "cuProfilerStop", err, errName, errString);
}
