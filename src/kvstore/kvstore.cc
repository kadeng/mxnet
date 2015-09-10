/*!
 * Copyright (c) 2015 by Contributors
 * \file kvstore.cc
 * \brief implement kv_store
 */
#include "mxnet/kvstore.h"
#include <stdlib.h>
#include "dmlc/logging.h"
#include "kvstore_local.h"

namespace mxnet {

void KVStore::InitDevices(const std::vector<Context>& devices) {
  CHECK(impl_ == NULL) << "double initialization, call Stop() first";
  char* num_worker = getenv("DMLC_NUM_WORKER");
  if (num_worker == NULL || atoi(num_worker) == 1) {
    impl_ = new KVStoreLocal();
  } else {
    LOG(FATAL) << "not implemented yet";
  }
  impl_->InitDevices(devices);
}

}  // namespace mxnet