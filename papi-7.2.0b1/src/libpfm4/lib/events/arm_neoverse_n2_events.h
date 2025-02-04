/*
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * ARM Neoverse N2
 * Based on ARM Neoverse N2 Technical Reference Manual rev 0
 * Section 18.1 Performance Monitors events
 */

static const arm_entry_t arm_n2_pe[]={
	{.name = "SW_INCR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x00,
	 .desc = "Instruction architecturally executed (condition check pass) software increment"
	},
	{.name = "L1I_CACHE_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x01,
	 .desc = "Level 1 instruction cache refills"
	},
	{.name = "L1I_TLB_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x02,
	 .desc = "Level 1 instruction TLB refills"
	},
	{.name = "L1D_CACHE_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x03,
	 .desc = "Level 1 data cache refills"
	},
	{.name = "L1D_CACHE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x04,
	 .desc = "Level 1 data cache accesses"
	},
	{.name = "L1D_TLB_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x05,
	 .desc = "Level 1 data TLB refills"
	},
	{.name = "INST_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x08,
	 .desc = "Instructions architecturally executed"
	},
	{.name = "EXC_TAKEN",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x09,
	 .desc = "Exceptions taken"
	},
	{.name = "EXC_RETURN",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x0a,
	 .desc = "Instructions architecturally executed (condition check pass) - Exception return"
	},
	{.name = "CID_WRITE_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x0b,
	 .desc = "Instructions architecturally executed (condition check pass) - Write to CONTEXTIDR",
	},
	{.name = "BR_MIS_PRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x10,
	 .desc = "Mispredicted or not predicted branches speculatively executed"
	},
	{.name = "CPU_CYCLES",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x11,
	 .desc = "Cycles"
	},
	{.name = "BR_PRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x12,
	 .desc = "Predictable branches speculatively executed"
	},
	{.name = "MEM_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x13,
	 .desc = "Data memory accesses"
	},
	{.name = "L1I_CACHE_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x14,
	 .desc = "Level 1 instruction cache accesses"
	},
	{.name = "L1D_CACHE_WB",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x15,
	 .desc = "Level 1 data cache write-backs"
	},
	{.name = "L2D_CACHE_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x16,
	 .equiv = "L2D_CACHE",
	 .desc = "Level 2 data cache accesses (alias to L2D_CACHE)"
	},
	{.name = "L2D_CACHE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x16,
	 .desc = "Level 2 data cache accesses"
	},
	{.name = "L2D_CACHE_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x17,
	 .desc = "Level 2 data cache refills"
	},
	{.name = "L2D_CACHE_WB",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x18,
	 .desc = "Level 2 data cache write-backs"
	},
	{.name = "BUS_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x19,
	 .desc = "Counts every beat of data transferred over the data channels between the core and the SCU"
	},
	{.name = "MEMORY_ERROR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x1a,
	 .desc = "Local memory errors"
	},
	{.name = "INST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x1b,
	 .desc = "Instructions speculatively executed"
	},
	{.name = "TTBR_WRITE_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x1c,
	 .desc = "Instructions architecturally executed (condition check pass, write to TTBR). Counts writes to TTBR0_EL1/TTBR1_EL1 in aarch64 mode"
	},
	{.name = "BUS_MASTER_CYCLE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x1d,
	 .desc = "Bus cycles. This event duplicate cycles",
	},
	{.name = "COUNTER_OVERFLOW",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x1e,
	 .desc = "For odd-numbered counters, this event increments the count by one for each overflow of the preceding even-numbered counter. There is no increment for even-numbered counters",
	},
	{.name = "L2D_CACHE_ALLOCATE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x20,
	 .desc = "Level 2 data/unified cache allocations without refill"
	},
	{.name = "BR_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x21,
	 .desc = "Counts all branches on the architecturally executed path that would incur cost if mispredicted"
	},
	{.name = "BR_MIS_PRED_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x22,
	 .desc = "Instructions executed, mis-predicted branch. All instructions counted by BR_RETIRED that were not correctly predicted"
	},
	{.name = "STALL_FRONTEND",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x23,
	 .desc = "Cycles in which no operation issued because there were no operations to issue"
	},
	{.name = "STALL_BACKEND",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x24,
	 .desc = "Cycles in which no operation issued due to back-end resources being unavailable"
	},
	{.name = "L1D_TLB",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x25,
	 .desc = "Level 1 data TLB accesses"
	},
	{.name = "L1I_TLB",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x26,
	 .desc = "Instruction TLB accesses"
	},
	{.name = "L3D_CACHE_ALLOCATE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x29,
	 .desc = "Attributable L3 data or unified cache allocations without a refill. Counts any full cache line write into the L3 cache which does not case a linefill, including write-backs from L2 to L3 and full line write which do not allocate into L2",
	},
	{.name = "L3D_CACHE_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x2a,
	 .desc = "Attributable L3 unified cache refills. Counts any cacheable read transaction returning data from the SCU for which the data source was outside the cluster",
	},
	{.name = "L3D_CACHE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x2b,
	 .desc = "Attributable L3 unified cache accesses. Counts any cacheable read transaction returning data from the SCU, or any cacheable write to the SCU",
	},
	{.name = "L2D_TLB_REFILL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x2d,
	 .desc = "Attributable L2 data or unified TLB refills. Counts on any refill of the L2TLB caused by either an instruction or data access (MMU must be enabled)",
	},
	{.name = "L2D_TLB_REQ",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x2f,
	 .desc = "Attributable L2 TLB accesses. Counts on any access to the MMUTC (caused by a refill of any of the L1 TLBs). This event does not count if the MMU is disabled",
	},
	{.name = "L2D_TLB",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x2f,
	 .equiv = "L2D_TLB_REQ",
	 .desc = "Attributable L2 TLB accesses. Counts on any access to the MMUTC (caused by a refill of any of the L1 TLBs). This event does not count if the MMU is disabled",
	},
	{.name = "REMOTE_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x31,
	 .desc = "Number of accesses to another socket",
	},
	{.name = "DTLB_WALK",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x34,
	 .desc = "Accesses to the data TLB that caused a page walk. Counts any data access which causes L2D_TLB_REFILL to count",
	},
	{.name = "ITLB_WALK",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x35,
	 .desc = "Accesses to the instruction TLB that caused a page walk. Counts any instruction which causes L2D_TLB_REFILL to count",
	},
	{.name = "LL_CACHE_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x36,
	 .desc = "Last Level cache accesses for reads",
	},
	{.name = "LL_CACHE_MISS_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x37,
	 .desc = "Last Level cache misses for reads",
	},
	{.name = "L1D_CACHE_LMISS_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x39,
	 .desc = "Counts the number Level 1 data cache long-latency misses",
	},
	{.name = "OP_RETIRED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3a,
	 .desc = "Counts the number of micro-ops architecturally executed",
	},
	{.name = "OP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3b,
	 .desc = "Counts the number of speculatively executed micro-ops",
	},
	{.name = "STALL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3c,
	 .desc = "Counts cycles in which no operation is sent for execution",
	},
	{.name = "STALL_SLOT_BACKEND",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3d,
	 .desc = "No operation sent for execution on a slot due to the backend",
	},
	{.name = "STALL_SLOT_FRONTEND",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3e,
	 .desc = "No operation sent for execution on a slot due to the frontend",
	},
	{.name = "STALL_SLOT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x3f,
	 .desc = "No operation sent for execution on a slot",
	},
	{.name = "L1D_CACHE_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x40,
	 .desc = "Level 1 data cache read accesses"
	},
	{.name = "L1D_CACHE_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x41,
	 .desc = "Level 1 data cache write accesses"
	},
	{.name = "L1D_CACHE_REFILL_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x42,
	 .desc = "Level 1 data cache read refills"
	},
	{.name = "L1D_CACHE_REFILL_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x43,
	 .desc = "Level 1 data cache write refills"
	},
	{.name = "L1D_CACHE_REFILL_INNER",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x44,
	 .desc = "Level 1 data cache refills, inner. Counts any L1D cache line fill which hits in the L2, L3 or another core in the cluster"
	},
	{.name = "L1D_CACHE_REFILL_OUTER",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x45,
	 .desc = "Level 1 data cache refills, outer. Counts any L1D cache line fill which does not hit in the L2, L3 or another core in the cluster and instead obtains data from outside the cluster"
	},
	{.name = "L1D_CACHE_WB_VICTIM",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x46,
	 .desc = "Level 1 data cache write-backs (victim eviction)",
	},
	{.name = "L1D_CACHE_WB_CLEAN",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x47,
	 .desc = "Level 1 data cache write-backs (clean and coherency eviction)",
	},
	{.name = "L1D_CACHE_INVAL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x48,
	 .desc = "Level 1 data cache invalidations"
	},
	{.name = "L1D_TLB_REFILL_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4c,
	 .desc = "Level 1 data TLB read refills"
	},
	{.name = "L1D_TLB_REFILL_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4d,
	 .desc = "Level 1 data TLB write refills"
	},
	{.name = "L1D_TLB_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4e,
	 .desc = "Level 1 data TLB read accesses"
	},
	{.name = "L1D_TLB_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4f,
	 .desc = "Level 1 data TLB write accesses"
	},
	{.name = "L2D_CACHE_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x50,
	 .desc = "Level 2 data cache read accesses"
	},
	{.name = "L2D_CACHE_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x51,
	 .desc = "Level 2 data cache write accesses"
	},
	{.name = "L2D_CACHE_REFILL_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x52,
	 .desc = "Level 2 data cache read refills"
	},
	{.name = "L2D_CACHE_REFILL_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x53,
	 .desc = "Level 2 data cache write refills"
	},
	{.name = "L2D_CACHE_WB_VICTIM",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x56,
	 .desc = "Level 2 data cache victim write-backs"
	},
	{.name = "L2D_CACHE_WB_CLEAN",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x57,
	 .desc = "Level 2 data cache cleaning and coherency write-backs"
	},
	{.name = "L2D_CACHE_INVAL",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x58,
	 .desc = "Level 2 data cache invalidations"
	},
	{.name = "L2D_TLB_REFILL_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x5c,
	 .desc = "Level 2 data TLB refills on read"
	},
	{.name = "L2D_TLB_REFILL_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x5d,
	 .desc = "Level 2 data TLB refills on write"
	},
	{.name = "L2D_TLB_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x5e,
	 .desc = "Level 2 data TLB accesses on read"
	},
	{.name = "L2D_TLB_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x5f,
	 .desc = "Level 2 data TLB accesses on write"
	},
	{.name = "BUS_ACCESS_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x60,
	 .desc = "Bus read accesses"
	},
	{.name = "BUS_ACCESS_WR",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x61,
	 .desc = "Bus write accesses"
	},
	{.name = "MEM_READ_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x66,
	 .desc = "Data memory read accesses"
	},
	{.name = "MEM_WRITE_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x67,
	 .desc = "Data memory write accesses"
	},

	{.name = "UNALIGNED_LD_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x68,
	 .desc = "Unaligned read accesses"
	},
	{.name = "UNALIGNED_ST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x69,
	 .desc = "Unaligned write accesses"
	},
	{.name = "UNALIGNED_LDST_ACCESS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x6a,
	 .desc = "Unaligned accesses"
	},

	{.name = "LDREX_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x6c,
	 .desc = "Exclusive operations speculatively executed - LDREX or LDX"
	},
	{.name = "STREX_PASS_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x6d,
	 .desc = "Exclusive operations speculative executed - STREX or STX pass"
	},
	{.name = "STREX_FAIL_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x6e,
	 .desc = "Exclusive operations speculative executed - STREX or STX fail"
	},
	{.name = "STREX_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x6f,
	 .desc = "Exclusive operations speculatively executed - STREX or STX"
	},
	{.name = "LD_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x70,
	 .desc = "Load instructions speculatively executed"
	},
	{.name = "ST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x71,
	 .desc = "Store instructions speculatively executed"
	},
	{.name = "DP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x73,
	 .desc = "Integer data processing instructions speculatively executed"
	},
	{.name = "ASE_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x74,
	 .desc = "Advanced SIMD instructions speculatively executed"
	},
	{.name = "VFP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x75,
	 .desc = "Floating-point instructions speculatively executed"
	},
	{.name = "PC_WRITE_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x76,
	 .desc = "Software change of the PC instruction speculatively executed"
	},
	{.name = "CRYPTO_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x77,
	 .desc = "Cryptographic instructions speculatively executed"
	},
	{.name = "BR_IMMED_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x78,
	 .desc = "Immediate branches speculatively executed"
	},
	{.name = "BR_RET_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x79,
	 .desc = "Return branches speculatively executed"
	},
	{.name = "BR_INDIRECT_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x7a,
	 .desc = "Indirect branches speculatively executed"
	},
	{.name = "ISB_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x7c,
	 .desc = "ISB barriers speculatively executed"
	},
	{.name = "DSB_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x7d,
	 .desc = "DSB barriers speculatively executed"
	},
	{.name = "DMB_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x7e,
	 .desc = "DMB barriers speculatively executed"
	},
	{.name = "EXC_UNDEF",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x81,
	 .desc = "Undefined exceptions taken locally"
	},
	{.name = "EXC_SVC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x82,
	 .desc = "Exceptions taken, supervisor call"
	},
	{.name = "EXC_PABORT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x83,
	 .desc = "Exceptions taken, instruction abort"
	},
	{.name = "EXC_DABORT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x84,
	 .desc = "Exceptions taken locally, data abort or SError"
	},
	{.name = "EXC_IRQ",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x86,
	 .desc = "Exceptions taken locally, IRQ"
	},
	{.name = "EXC_FIQ",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x87,
	 .desc = "Exceptions taken locally, FIQ"
	},
	{.name = "EXC_SMC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x88,
	 .desc = "Exceptions taken locally, secure monitor call"
	},
	{.name = "EXC_HVC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8a,
	 .desc = "Exceptions taken, hypervisor call"
	},
	{.name = "EXC_TRAP_PABORT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8b,
	 .desc = "Exceptions taken, instruction abort not taken locally"
	},
	{.name = "EXC_TRAP_DABORT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8c,
	 .desc = "Exceptions taken, data abort or SError not taken locally"
	},
	{.name = "EXC_TRAP_OTHER",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8d,
	 .desc = "Exceptions taken, other traps not taken locally"
	},
	{.name = "EXC_TRAP_IRQ",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8e,
	 .desc = "Exceptions taken, irq not taken locally"
	},
	{.name = "EXC_TRAP_FIQ",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8f,
	 .desc = "Exceptions taken, fiq not taken locally"
	},
	{.name = "RC_LD_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x90,
	 .desc = "Release consistency instructions speculatively executed (load-acquire)",
	},
	{.name = "RC_ST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x91,
	 .desc = "Release consistency instructions speculatively executed (store-release)",
	},
	{.name = "L3_CACHE_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0xa0,
	 .desc = "L3 cache reads",
	},
	{.name = "SAMPLE_POP",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4000,
	 .desc = "Number of operations that might be sampled by SPE, whether or not the operation was sampled",
	},
	{.name = "SAMPLE_FEED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4001,
	 .desc = "Number of times the SPE sample interval counter reaches zero and is reloaded",
	},
	{.name = "SAMPLE_FILTRATE",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4002,
	 .desc = "Number of times SPE completed sample record passes the SPE filters and is written to the buffer"
	},
	{.name = "SAMPLE_COLLISION",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4003,
	 .desc = "Number of times SPE has a sample record taken when the previous sampled operation has not yet completed its record"
	},
	{.name = "CNT_CYCLES",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4004,
	 .desc = "Constant frequency cycles",
	},
	{.name = "STALL_BACKEND_MEM",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4005,
	 .desc = "No operation sent due to the backend and memory stalls",
	},
	{.name = "L1I_CACHE_LMISS",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4006,
	 .desc = "Counts L1 instruction cache long latency misses",
	},
	{.name = "L2D_CACHE_LMISS_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4009,
	 .desc = "Counts L2 cache long latency misses",
	},
	{.name = "L3D_CACHE_LMISS_RD",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x400b,
	 .desc = "Counts L3 cache long latency misses",
	},
	{.name = "TRB_WRAP",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x400c,
	 .desc = "Counts number of time the Trace buffer current write pointer wrapped",
	},
	{.name = "TRCEXTOUT0",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4010,
	 .desc = "PE Trace unit extern output 0",
	},
	{.name = "TRCEXTOUT1",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4011,
	 .desc = "PE Trace unit extern output 1",
	},
	{.name = "TRCEXTOUT2",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4012,
	 .desc = "PE Trace unit extern output 2",
	},
	{.name = "TRCEXTOUT3",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4013,
	 .desc = "PE Trace unit extern output 3",
	},
	{.name = "CTI_TRIGOUT4",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4018,
	 .desc = "Cross-trigger interface output trigger 4",
	},
	{.name = "CTI_TRIGOUT5",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4019,
	 .desc = "Cross-trigger interface output trigger 5",
	},
	{.name = "CTI_TRIGOUT6",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x401a,
	 .desc = "Cross-trigger interface output trigger 6",
	},
	{.name = "CTI_TRIGOUT7",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x401b,
	 .desc = "Cross-trigger interface output trigger r",
	},
	{.name = "LDST_ALIGN_LAT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4020,
	 .desc = "Accesses with additonal latency from aligment",
	},
	{.name = "LD_ALIGN_LAT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4021,
	 .desc = "Loads with additonal latency from aligment",
	},
	{.name = "ST_ALIGN_LAT",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4022,
	 .desc = "Stores with additonal latency from aligment",
	},
	{.name = "MEM_ACCESS_CHECKED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4024,
	 .desc = "Checked data memory acess",
	},
	{.name = "MEM_ACCESS_RD_CHECKED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4025,
	 .desc = "Checked data memory read acess",
	},
	{.name = "MEM_ACCESS_WR_CHECKED",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x4026,
	 .desc = "Checked data memory write acess",
	},
	{.name = "ASE_INST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8005,
	 .desc = "Advanced SIMD operations sepculatively executed",
	},
	{.name = "SVE_INST_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8006,
	 .desc = "SVE operations sepculatively executed",
	},
	{.name = "FP_HP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8014,
	 .desc = "Half precision floating-point operations sepculatively executed",
	},
	{.name = "FP_SP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8018,
	 .desc = "Single precision floating-point operations sepculatively executed",
	},
	{.name = "FP_DP_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x801c,
	 .desc = "Double precision floating-point operations sepculatively executed",
	},
	{.name = "SVE_PRED_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8074,
	 .desc = "SVE predicated operations speculatively executed",
	},
	{.name = "SVE_PRED_EMPTY_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8075,
	 .desc = "SVE predicated operations with no active predicates speculatively executed",
	},
	{.name = "SVE_PRED_FULL_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8076,
	 .desc = "SVE predicated operations with all active predicates speculatively executed",
	},
	{.name = "SVE_PRED_PARTIAL_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8077,
	 .desc = "SVE predicated operations with partially active predicates speculatively executed",
	},
	{.name = "SVE_PRED_NOT_FULL_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x8079,
	 .desc = "SVE predicated operations speculatively executed with a governing predicate in which at least one element is false",
	},
	{.name = "SVE_LDFF_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80bc,
	 .desc = "SVE first-fault load operations speculatively executed",
	},
	{.name = "SVE_LDFF_FAULT_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80bd,
	 .desc = "SVE first-fault load operations speculatively executed which set FFR bit to 0",
	},
	{.name = "FP_SCALE_OPS_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80c0,
	 .desc = "Scalable floating-point element operations sepculatively executed",
	},
	{.name = "FP_FIXED_OPS_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80c1,
	 .desc = "Non-scalable floating-point element operations sepculatively executed",
	},
	{.name = "ASE_SVE_INT8_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80e3,
	 .desc = "Operations counted by ASE_SVE_INT_SPEC where the large type is a 8-bit integer",
	},
	{.name = "ASE_SVE_INT16_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80e7,
	 .desc = "Operations counted by ASE_SVE_INT_SPEC where the large type is a 16-bit integer",
	},
	{.name = "ASE_SVE_INT32_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80eb,
	 .desc = "Operations counted by ASE_SVE_INT_SPEC where the large type is a 32-bit integer",
	},
	{.name = "ASE_SVE_INT64_SPEC",
	 .modmsk = ARMV9_ATTRS,
	 .code = 0x80ef,
	 .desc = "Operations counted by ASE_SVE_INT_SPEC where the large type is a 64-bit integer",
	},
};
