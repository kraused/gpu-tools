
#ifndef NVIDIA_CUDA_CUDAAPI_H_INCLUDED
#define NVIDIA_CUDA_CUDAAPI_H_INCLUDED 1

#include <cuda.h>
#include <cudaProfiler.h>

typedef void (*Nvcu_Return_Handling_Function)(const char *caller,
                                              const char *callee,
                                              CUresult err,
                                              const char *errname,
                                              const char *errstr);

extern Nvcu_Return_Handling_Function nvcu_return_handler;

void Nvcu_Default_Return_Handler(const char *caller,
                                 const char *callee,
                                 CUresult err,
                                 const char *errname,
                                 const char *errstr);

void Nvcu_Debug_Return_Handler(const char *caller,
                               const char *callee,
                               CUresult err,
                               const char *errname,
                               const char *errstr);

/* Wrapper around CUDA driver API library calls.
 *
 * Generated with python2 wrap-cuda.py --prototypes.
 */

void Nvcu_GetErrorName(CUresult, const char**);
void Nvcu_GetErrorString(CUresult, const char**);
void Nvcu_Init(unsigned int);
void Nvcu_DriverGetVersion(int*);
void Nvcu_DeviceGet(CUdevice*, int);
void Nvcu_DeviceGetAttribute(int*, CUdevice_attribute, CUdevice);
void Nvcu_DeviceGetCount(int*);
void Nvcu_DeviceGetName(char*, int, CUdevice);
void Nvcu_DeviceTotalMem(size_t*, CUdevice);
void Nvcu_DevicePrimaryCtxGetState(CUdevice, unsigned int*, int*);
void Nvcu_DevicePrimaryCtxRelease(CUdevice);
void Nvcu_DevicePrimaryCtxReset(CUdevice);
void Nvcu_DevicePrimaryCtxRetain(CUcontext*, CUdevice);
void Nvcu_DevicePrimaryCtxSetFlags(CUdevice, unsigned int);
void Nvcu_CtxCreate(CUcontext*, unsigned int, CUdevice);
void Nvcu_CtxDestroy(CUcontext);
void Nvcu_CtxGetApiVersion(CUcontext, unsigned int*);
void Nvcu_CtxGetCacheConfig(CUfunc_cache*);
void Nvcu_CtxGetCurrent(CUcontext*);
void Nvcu_CtxGetDevice(CUdevice*);
void Nvcu_CtxGetFlags(unsigned int*);
void Nvcu_CtxGetLimit(size_t*, CUlimit);
void Nvcu_CtxGetSharedMemConfig(CUsharedconfig*);
void Nvcu_CtxGetStreamPriorityRange(int*, int*);
void Nvcu_CtxPopCurrent(CUcontext*);
void Nvcu_CtxPushCurrent(CUcontext);
void Nvcu_CtxSetCacheConfig(CUfunc_cache);
void Nvcu_CtxSetCurrent(CUcontext);
void Nvcu_CtxSetLimit(CUlimit, size_t);
void Nvcu_CtxSetSharedMemConfig(CUsharedconfig);
void Nvcu_CtxSynchronize();
void Nvcu_LinkAddData(CUlinkState, CUjitInputType, void*, size_t, const char*, unsigned int, CUjit_option*, void**);
void Nvcu_LinkAddFile(CUlinkState, CUjitInputType, const char*, unsigned int, CUjit_option*, void**);
void Nvcu_LinkComplete(CUlinkState, void**, size_t*);
void Nvcu_LinkCreate(unsigned int, CUjit_option*, void**, CUlinkState*);
void Nvcu_LinkDestroy(CUlinkState);
void Nvcu_ModuleGetFunction(CUfunction*, CUmodule, const char*);
void Nvcu_ModuleGetGlobal(CUdeviceptr*, size_t*, CUmodule, const char*);
void Nvcu_ModuleGetSurfRef(CUsurfref*, CUmodule, const char*);
void Nvcu_ModuleGetTexRef(CUtexref*, CUmodule, const char*);
void Nvcu_ModuleLoad(CUmodule*, const char*);
void Nvcu_ModuleLoadData(CUmodule*, const void*);
void Nvcu_ModuleLoadDataEx(CUmodule*, const void*, unsigned int, CUjit_option*, void**);
void Nvcu_ModuleLoadFatBinary(CUmodule*, const void*);
void Nvcu_ModuleUnload(CUmodule);
void Nvcu_Array3DCreate(CUarray*, const CUDA_ARRAY3D_DESCRIPTOR*);
void Nvcu_Array3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR*, CUarray);
void Nvcu_ArrayCreate(CUarray*, const CUDA_ARRAY_DESCRIPTOR*);
void Nvcu_ArrayDestroy(CUarray);
void Nvcu_ArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR*, CUarray);
void Nvcu_DeviceGetByPCIBusId(CUdevice*, const char*);
void Nvcu_DeviceGetPCIBusId(char*, int, CUdevice);
void Nvcu_IpcCloseMemHandle(CUdeviceptr);
void Nvcu_IpcGetEventHandle(CUipcEventHandle*, CUevent);
void Nvcu_IpcGetMemHandle(CUipcMemHandle*, CUdeviceptr);
void Nvcu_IpcOpenEventHandle(CUevent*, CUipcEventHandle);
void Nvcu_IpcOpenMemHandle(CUdeviceptr*, CUipcMemHandle, unsigned int);
void Nvcu_MemAlloc(CUdeviceptr*, size_t);
void Nvcu_MemAllocHost(void**, size_t);
void Nvcu_MemAllocManaged(CUdeviceptr*, size_t, unsigned int);
void Nvcu_MemAllocPitch(CUdeviceptr*, size_t*, size_t, size_t, unsigned int);
void Nvcu_MemFree(CUdeviceptr);
void Nvcu_MemFreeHost(void*);
void Nvcu_MemGetAddressRange(CUdeviceptr*, size_t*, CUdeviceptr);
void Nvcu_MemGetInfo(size_t*, size_t*);
void Nvcu_MemHostAlloc(void**, size_t, unsigned int);
void Nvcu_MemHostGetDevicePointer(CUdeviceptr*, void*, unsigned int);
void Nvcu_MemHostGetFlags(unsigned int*, void*);
void Nvcu_MemHostRegister(void*, size_t, unsigned int);
void Nvcu_MemHostUnregister(void*);
void Nvcu_Memcpy(CUdeviceptr, CUdeviceptr, size_t);
void Nvcu_Memcpy2D(const CUDA_MEMCPY2D*);
void Nvcu_Memcpy2DAsync(const CUDA_MEMCPY2D*, CUstream);
void Nvcu_Memcpy2DUnaligned(const CUDA_MEMCPY2D*);
void Nvcu_Memcpy3D(const CUDA_MEMCPY3D*);
void Nvcu_Memcpy3DAsync(const CUDA_MEMCPY3D*, CUstream);
void Nvcu_Memcpy3DPeer(const CUDA_MEMCPY3D_PEER*);
void Nvcu_Memcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER*, CUstream);
void Nvcu_MemcpyAsync(CUdeviceptr, CUdeviceptr, size_t, CUstream);
void Nvcu_MemcpyAtoA(CUarray, size_t, CUarray, size_t, size_t);
void Nvcu_MemcpyAtoD(CUdeviceptr, CUarray, size_t, size_t);
void Nvcu_MemcpyAtoH(void*, CUarray, size_t, size_t);
void Nvcu_MemcpyAtoHAsync(void*, CUarray, size_t, size_t, CUstream);
void Nvcu_MemcpyDtoA(CUarray, size_t, CUdeviceptr, size_t);
void Nvcu_MemcpyDtoD(CUdeviceptr, CUdeviceptr, size_t);
void Nvcu_MemcpyDtoDAsync(CUdeviceptr, CUdeviceptr, size_t, CUstream);
void Nvcu_MemcpyDtoH(void*, CUdeviceptr, size_t);
void Nvcu_MemcpyDtoHAsync(void*, CUdeviceptr, size_t, CUstream);
void Nvcu_MemcpyHtoA(CUarray, size_t, const void*, size_t);
void Nvcu_MemcpyHtoAAsync(CUarray, size_t, const void*, size_t, CUstream);
void Nvcu_MemcpyHtoD(CUdeviceptr, const void*, size_t);
void Nvcu_MemcpyHtoDAsync(CUdeviceptr, const void*, size_t, CUstream);
void Nvcu_MemcpyPeer(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t);
void Nvcu_MemcpyPeerAsync(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream);
void Nvcu_MemsetD16(CUdeviceptr, unsigned short, size_t);
void Nvcu_MemsetD16Async(CUdeviceptr, unsigned short, size_t, CUstream);
void Nvcu_MemsetD2D16(CUdeviceptr, size_t, unsigned short, size_t, size_t);
void Nvcu_MemsetD2D16Async(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream);
void Nvcu_MemsetD2D32(CUdeviceptr, size_t, unsigned int, size_t, size_t);
void Nvcu_MemsetD2D32Async(CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream);
void Nvcu_MemsetD2D8(CUdeviceptr, size_t, unsigned char, size_t, size_t);
void Nvcu_MemsetD2D8Async(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream);
void Nvcu_MemsetD32(CUdeviceptr, unsigned int, size_t);
void Nvcu_MemsetD32Async(CUdeviceptr, unsigned int, size_t, CUstream);
void Nvcu_MemsetD8(CUdeviceptr, unsigned char, size_t);
void Nvcu_MemsetD8Async(CUdeviceptr, unsigned char, size_t, CUstream);
void Nvcu_MipmappedArrayCreate(CUmipmappedArray*, const CUDA_ARRAY3D_DESCRIPTOR*, unsigned int);
void Nvcu_MipmappedArrayDestroy(CUmipmappedArray);
void Nvcu_MipmappedArrayGetLevel(CUarray*, CUmipmappedArray, unsigned int);
void Nvcu_PointerGetAttribute(void*, CUpointer_attribute, CUdeviceptr);
void Nvcu_PointerGetAttributes(unsigned int, CUpointer_attribute*, void**, CUdeviceptr);
void Nvcu_PointerSetAttribute(const void*, CUpointer_attribute, CUdeviceptr);
void Nvcu_StreamAddCallback(CUstream, CUstreamCallback, void*, unsigned int);
void Nvcu_StreamAttachMemAsync(CUstream, CUdeviceptr, size_t, unsigned int);
void Nvcu_StreamCreate(CUstream*, unsigned int);
void Nvcu_StreamCreateWithPriority(CUstream*, unsigned int, int);
void Nvcu_StreamDestroy(CUstream);
void Nvcu_StreamGetFlags(CUstream, unsigned int*);
void Nvcu_StreamGetPriority(CUstream, int*);
void Nvcu_StreamQuery(CUstream);
void Nvcu_StreamSynchronize(CUstream);
void Nvcu_StreamWaitEvent(CUstream, CUevent, unsigned int);
void Nvcu_EventCreate(CUevent*, unsigned int);
void Nvcu_EventDestroy(CUevent);
void Nvcu_EventElapsedTime(float*, CUevent, CUevent);
void Nvcu_EventQuery(CUevent);
void Nvcu_EventRecord(CUevent, CUstream);
void Nvcu_EventSynchronize(CUevent);
void Nvcu_FuncGetAttribute(int*, CUfunction_attribute, CUfunction);
void Nvcu_FuncSetCacheConfig(CUfunction, CUfunc_cache);
void Nvcu_FuncSetSharedMemConfig(CUfunction, CUsharedconfig);
void Nvcu_LaunchKernel(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void**, void**);
void Nvcu_OccupancyMaxActiveBlocksPerMultiprocessor(int*, CUfunction, int, size_t);
void Nvcu_OccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int*, CUfunction, int, size_t, unsigned int);
void Nvcu_OccupancyMaxPotentialBlockSize(int*, int*, CUfunction, CUoccupancyB2DSize, size_t, int);
void Nvcu_OccupancyMaxPotentialBlockSizeWithFlags(int*, int*, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int);
void Nvcu_TexRefGetAddress(CUdeviceptr*, CUtexref);
void Nvcu_TexRefGetAddressMode(CUaddress_mode*, CUtexref, int);
void Nvcu_TexRefGetArray(CUarray*, CUtexref);
void Nvcu_TexRefGetFilterMode(CUfilter_mode*, CUtexref);
void Nvcu_TexRefGetFlags(unsigned int*, CUtexref);
void Nvcu_TexRefGetFormat(CUarray_format*, int*, CUtexref);
void Nvcu_TexRefGetMaxAnisotropy(int*, CUtexref);
void Nvcu_TexRefGetMipmapFilterMode(CUfilter_mode*, CUtexref);
void Nvcu_TexRefGetMipmapLevelBias(float*, CUtexref);
void Nvcu_TexRefGetMipmapLevelClamp(float*, float*, CUtexref);
void Nvcu_TexRefGetMipmappedArray(CUmipmappedArray*, CUtexref);
void Nvcu_TexRefSetAddress(size_t*, CUtexref, CUdeviceptr, size_t);
void Nvcu_TexRefSetAddress2D(CUtexref, const CUDA_ARRAY_DESCRIPTOR*, CUdeviceptr, size_t);
void Nvcu_TexRefSetAddressMode(CUtexref, int, CUaddress_mode);
void Nvcu_TexRefSetArray(CUtexref, CUarray, unsigned int);
void Nvcu_TexRefSetFilterMode(CUtexref, CUfilter_mode);
void Nvcu_TexRefSetFlags(CUtexref, unsigned int);
void Nvcu_TexRefSetFormat(CUtexref, CUarray_format, int);
void Nvcu_TexRefSetMaxAnisotropy(CUtexref, unsigned int);
void Nvcu_TexRefSetMipmapFilterMode(CUtexref, CUfilter_mode);
void Nvcu_TexRefSetMipmapLevelBias(CUtexref, float);
void Nvcu_TexRefSetMipmapLevelClamp(CUtexref, float, float);
void Nvcu_TexRefSetMipmappedArray(CUtexref, CUmipmappedArray, unsigned int);
void Nvcu_SurfRefGetArray(CUarray*, CUsurfref);
void Nvcu_SurfRefSetArray(CUsurfref, CUarray, unsigned int);
void Nvcu_TexObjectCreate(CUtexObject*, const CUDA_RESOURCE_DESC*, const CUDA_TEXTURE_DESC*, const CUDA_RESOURCE_VIEW_DESC*);
void Nvcu_TexObjectDestroy(CUtexObject);
void Nvcu_TexObjectGetResourceDesc(CUDA_RESOURCE_DESC*, CUtexObject);
void Nvcu_TexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC*, CUtexObject);
void Nvcu_TexObjectGetTextureDesc(CUDA_TEXTURE_DESC*, CUtexObject);
void Nvcu_SurfObjectCreate(CUsurfObject*, const CUDA_RESOURCE_DESC*);
void Nvcu_SurfObjectDestroy(CUsurfObject);
void Nvcu_SurfObjectGetResourceDesc(CUDA_RESOURCE_DESC*, CUsurfObject);
void Nvcu_CtxDisablePeerAccess(CUcontext);
void Nvcu_CtxEnablePeerAccess(CUcontext, unsigned int);
void Nvcu_DeviceCanAccessPeer(int*, CUdevice, CUdevice);
void Nvcu_GraphicsMapResources(unsigned int, CUgraphicsResource*, CUstream);
void Nvcu_GraphicsResourceGetMappedMipmappedArray(CUmipmappedArray*, CUgraphicsResource);
void Nvcu_GraphicsResourceGetMappedPointer(CUdeviceptr*, size_t*, CUgraphicsResource);
void Nvcu_GraphicsResourceSetMapFlags(CUgraphicsResource, unsigned int);
void Nvcu_GraphicsSubResourceGetMappedArray(CUarray*, CUgraphicsResource, unsigned int, unsigned int);
void Nvcu_GraphicsUnmapResources(unsigned int, CUgraphicsResource*, CUstream);
void Nvcu_GraphicsUnregisterResource(CUgraphicsResource);
void Nvcu_ProfilerInitialize(const char*, const char*, CUoutput_mode);
void Nvcu_ProfilerStart();
void Nvcu_ProfilerStop();

#endif

