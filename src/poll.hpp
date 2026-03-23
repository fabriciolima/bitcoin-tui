#pragma once

#include <functional>
#include <mutex>
#include <string>

#include "rpc_client.hpp"
#include "state.hpp"

// Two-phase RPC poll: commits core data (blockchain/network/mempool/peers) and
// calls on_core_ready before the slower per-block stats fetches.
// blocks_dir: absolute path to the blocks/ directory for disk usage calculation.
void poll_rpc(RpcClient& rpc, AppState& state, std::mutex& mtx,
              const std::string& blocks_dir,
              const std::function<void()>& on_core_ready = nullptr);
