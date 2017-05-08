/*
 * Copyright 2017 MapD Technologies, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CPUBUFFER_H
#define CPUBUFFER_H

#include "../Buffer.h"

namespace CudaMgr_Namespace {
class CudaMgr;
}

namespace Buffer_Namespace {
class CpuBuffer : public Buffer {
 public:
  CpuBuffer(BufferMgr* bm,
            BufferList::iterator segIt,
            const int deviceId,
            CudaMgr_Namespace::CudaMgr* cudaMgr,
            const size_t pageSize = 512,
            const size_t numBytes = 0);

  virtual inline Data_Namespace::MemoryLevel getType() const { return CPU_LEVEL; }

 private:
  void readData(int8_t* const dst,
                const size_t numBytes,
                const size_t offset = 0,
                const MemoryLevel dstMemoryLevel = CPU_LEVEL,
                const int dstDeviceId = -1);
  void writeData(int8_t* const src,
                 const size_t numBytes,
                 const size_t offset = 0,
                 const MemoryLevel srcMemoryLevel = CPU_LEVEL,
                 const int srcDeviceId = -1);
  CudaMgr_Namespace::CudaMgr* cudaMgr_;
};
}  // Buffer_Namespace

#endif  // CPUBUFFER_H
