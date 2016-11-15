/*
 * QEMU model of the AXIPCIE_MAIN Xilinx PCIe NWL
 *
 * Copyright (c) 2016 Xilinx Inc.
 *
 * Autogenerated by xregqemu.py 2016-11-03.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/sysbus.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "qapi/error.h"

#include "hw/pci/msi.h"

#include "hw/pci/pci.h"
#include "hw/pci/pcie.h"
#include "hw/pci/pci_bus.h"
#include "hw/pci/pcie_host.h"
#include "hw/pci/pcie_port.h"

#ifndef XILINX_AXIPCIE_MAIN_ERR_DEBUG
#define XILINX_AXIPCIE_MAIN_ERR_DEBUG 0
#endif

#define TYPE_XILINX_AXIPCIE_MAIN "xlnx.nwl-pcie-main"

#define XILINX_AXIPCIE_MAIN(obj) \
     OBJECT_CHECK(AXIPCIE_MAIN, (obj), TYPE_XILINX_AXIPCIE_MAIN)

REG32(BRIDGE_CORE_CFG_PCIE_RX0, 0x0)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX0, CFG_DISABLE_PCIE_DMA_REG_ACCESS, 1, 17)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX0, CFG_DISABLE_PCIE_BRIDGE_REG_ACCESS, 1, 16)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX0, CFG_DMA_REG_BAR, 3, 0)
REG32(BRIDGE_CORE_CFG_PCIE_RX1, 0x4)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX1, CFG_RD_UR_IS_UR_OK1S_N, 1, 8)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX1, CFG_PCIE_RX_ARCACHE, 4, 4)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX1, CFG_PCIE_RX_AWCACHE, 4, 0)
REG32(BRIDGE_CORE_CFG_AXI_MASTER, 0x8)
    FIELD(BRIDGE_CORE_CFG_AXI_MASTER, CFG_M_MAX_RD_REQ_SIZE, 3, 4)
    FIELD(BRIDGE_CORE_CFG_AXI_MASTER, CFG_M_MAX_WR_REQ_SIZE, 3, 0)
REG32(BRIDGE_CORE_CFG_PCIE_TX, 0xc)
    FIELD(BRIDGE_CORE_CFG_PCIE_TX, CFG_PCIE_TX_CUT_THROUGH, 1, 0)
REG32(BRIDGE_CORE_CFG_INTERRUPT, 0x10)
    FIELD(BRIDGE_CORE_CFG_INTERRUPT, CFG_PCIE_INT_AXI_PCIE_N, 1, 0)
REG32(BRIDGE_CORE_CFG_RAM_DISABLE0, 0x14)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_SGL_DST_DIS_COR, 1, 14)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_SGL_SRC_DIS_COR, 1, 13)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_CH_REG_DIS_COR, 1, 12)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_MSIX_TAB_DIS_COR, 1, 11)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_AXI_S_W_DIS_COR, 1, 8)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_AXI_M_R_DIS_COR, 1, 6)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_S_CD_DIS_COR, 1, 5)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_S_RA_DIS_COR, 1, 4)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_S_W_DIS_COR, 1, 3)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_S_WA_DIS_COR, 1, 2)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_TX_W_DIS_COR, 1, 1)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE0, CFG_RAM_DMA_PCIE_M_R_DIS_COR, 1, 0)
REG32(BRIDGE_CORE_CFG_RAM_DISABLE1, 0x18)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_SGL_DST_DIS_ERR, 1, 14)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_SGL_SRC_DIS_ERR, 1, 13)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_CH_REG_DIS_ERR, 1, 12)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_MSIX_TAB_DIS_ERR, 1, 11)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_AXI_S_W_DIS_ERR, 1, 8)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_AXI_M_R_DIS_ERR, 1, 6)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_S_CD_DIS_ERR, 1, 5)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_S_RA_DIS_ERR, 1, 4)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_S_W_DIS_ERR, 1, 3)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_S_WA_DIS_ERR, 1, 2)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_TX_W_DIS_ERR, 1, 1)
    FIELD(BRIDGE_CORE_CFG_RAM_DISABLE1, CFG_RAM_DMA_PCIE_M_R_DIS_ERR, 1, 0)
REG32(BRIDGE_CORE_CFG_PCIE_RELAXED_ORDER, 0x1c)
    FIELD(BRIDGE_CORE_CFG_PCIE_RELAXED_ORDER, CFG_ENABLE_CFGIO_WR_RO, 1, 1)
    FIELD(BRIDGE_CORE_CFG_PCIE_RELAXED_ORDER, CFG_ENABLE_DMA_RO, 1, 0)
REG32(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, 0x20)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_DESIRED_VEN_MSG_VEN_ID,
          16, 16)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_DESIRED_VEN_MSG_VEN_INV,
          1, 15)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_DESIRED_VEN_MSG_EN, 1, 14)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_OTH_MSG_FWD, 1, 13)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_VEN_MSG_FWD, 1, 7)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_SLT_MSG_FWD, 1, 5)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_ERR_MSG_FWD, 1, 3)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_INT_MSG_FWD, 1, 2)
    FIELD(BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER, CFG_ENABLE_PM_MSG_FWD, 1, 1)
REG32(BRIDGE_CORE_CFG_RQ_REQ_ORDER, 0x24)
    FIELD(BRIDGE_CORE_CFG_RQ_REQ_ORDER, CFG_PCIE_REQ_ORDER_STRICT, 1, 31)
    FIELD(BRIDGE_CORE_CFG_RQ_REQ_ORDER, CFG_AXI_REQ_ORDER_STRICT, 1, 30)
    FIELD(BRIDGE_CORE_CFG_RQ_REQ_ORDER, CFG_AXI_REQ_ORDER_ID_MASK, 16, 0)
REG32(BRIDGE_CORE_CFG_PCIE_CREDIT, 0x28)
    FIELD(BRIDGE_CORE_CFG_PCIE_CREDIT, CFG_PCIE_CREDIT_EN, 1, 31)
    FIELD(BRIDGE_CORE_CFG_PCIE_CREDIT, CFG_PCIE_CREDIT_CH_INF, 1, 30)
    FIELD(BRIDGE_CORE_CFG_PCIE_CREDIT, CFG_PCIE_CREDIT_CD_INF, 1, 29)
    FIELD(BRIDGE_CORE_CFG_PCIE_CREDIT, CFG_PCIE_CREDIT_CH_VAL, 8, 16)
    FIELD(BRIDGE_CORE_CFG_PCIE_CREDIT, CFG_PCIE_CREDIT_CD_VAL, 12, 0)
REG32(BRIDGE_CORE_CFG_AXI_M_W_TICK_COUNT, 0x2c)
    FIELD(BRIDGE_CORE_CFG_AXI_M_W_TICK_COUNT, AXI_M_W_TICK_COUNT, 16, 0)
REG32(BRIDGE_CORE_CFG_AXI_M_R_TICK_COUNT, 0x30)
    FIELD(BRIDGE_CORE_CFG_AXI_M_R_TICK_COUNT, AXI_M_R_TICK_COUNT, 16, 0)
REG32(BRIDGE_CORE_CFG_CRS_RPL_TICK_COUNT, 0x34)
    FIELD(BRIDGE_CORE_CFG_CRS_RPL_TICK_COUNT, CRS_RPL_TICK_COUNT, 16, 0)
REG32(E_BREG_CAPABILITIES, 0x200)
    FIELD(E_BREG_CAPABILITIES, BREG_SIZE_MAX, 8, 24)
    FIELD(E_BREG_CAPABILITIES, BREG_SIZE_OFFSET, 8, 16)
    FIELD(E_BREG_CAPABILITIES, BREG_PRESENT, 1, 0)
REG32(E_BREG_STATUS, 0x204)
    FIELD(E_BREG_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_BREG_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_BREG_CONTROL, 0x208)
    FIELD(E_BREG_CONTROL, BREG_SIZE, 2, 16)
    FIELD(E_BREG_CONTROL, BREG_SECURITY_ENABLE, 1, 2)
    FIELD(E_BREG_CONTROL, BREG_ENABLE_FORCE, 1, 1)
    FIELD(E_BREG_CONTROL, BREG_ENABLE, 1, 0)
REG32(E_BREG_BASE_LO, 0x210)
    FIELD(E_BREG_BASE_LO, BREG_BASE_LO, 20, 12)
REG32(E_BREG_BASE_HI, 0x214)
REG32(E_ECAM_CAPABILITIES, 0x220)
    FIELD(E_ECAM_CAPABILITIES, ECAM_SIZE_MAX, 8, 24)
    FIELD(E_ECAM_CAPABILITIES, ECAM_SIZE_OFFSET, 8, 16)
    FIELD(E_ECAM_CAPABILITIES, ECAM_PRESENT, 1, 0)
REG32(E_ECAM_STATUS, 0x224)
    FIELD(E_ECAM_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_ECAM_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_ECAM_CONTROL, 0x228)
    FIELD(E_ECAM_CONTROL, ECAM_SIZE, 5, 16)
    FIELD(E_ECAM_CONTROL, ECAM_SECURITY_ENABLE, 1, 2)
    FIELD(E_ECAM_CONTROL, ECAM_ENABLE, 1, 0)
REG32(E_ECAM_BASE_LO, 0x230)
    FIELD(E_ECAM_BASE_LO, ECAM_BASE_LO, 20, 12)
REG32(E_ECAM_BASE_HI, 0x234)
REG32(E_MSXT_CAPABILITIES, 0x240)
    FIELD(E_MSXT_CAPABILITIES, MSXT_SIZE_MAX, 8, 24)
    FIELD(E_MSXT_CAPABILITIES, MSXT_SIZE_OFFSET, 8, 16)
    FIELD(E_MSXT_CAPABILITIES, MSXT_PRESENT, 1, 0)
REG32(E_MSXT_STATUS, 0x244)
    FIELD(E_MSXT_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_MSXT_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_MSXT_CONTROL, 0x248)
    FIELD(E_MSXT_CONTROL, MSXT_SIZE, 2, 16)
    FIELD(E_MSXT_CONTROL, MSXT_SECURITY_ENABLE, 1, 2)
    FIELD(E_MSXT_CONTROL, MSXT_ENABLE, 1, 0)
REG32(E_MSXT_BASE_LO, 0x250)
    FIELD(E_MSXT_BASE_LO, MSXT_BASE_LO, 20, 12)
REG32(E_MSXT_BASE_HI, 0x254)
REG32(E_MSXP_CAPABILITIES, 0x260)
    FIELD(E_MSXP_CAPABILITIES, MSXP_SIZE_MAX, 8, 24)
    FIELD(E_MSXP_CAPABILITIES, MSXP_SIZE_OFFSET, 8, 16)
    FIELD(E_MSXP_CAPABILITIES, MSXP_PRESENT, 1, 0)
REG32(E_MSXP_STATUS, 0x264)
    FIELD(E_MSXP_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_MSXP_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_MSXP_CONTROL, 0x268)
    FIELD(E_MSXP_CONTROL, MSXP_SIZE, 2, 16)
    FIELD(E_MSXP_CONTROL, MSXP_SECURITY_ENABLE, 1, 2)
    FIELD(E_MSXP_CONTROL, MSXP_ENABLE, 1, 0)
REG32(E_MSXP_BASE_LO, 0x270)
    FIELD(E_MSXP_BASE_LO, MSXP_BASE_LO, 20, 12)
REG32(E_MSXP_BASE_HI, 0x274)
REG32(E_DREG_CAPABILITIES, 0x280)
    FIELD(E_DREG_CAPABILITIES, DMA_SIZE_MAX, 8, 24)
    FIELD(E_DREG_CAPABILITIES, DMA_SIZE_OFFSET, 8, 16)
    FIELD(E_DREG_CAPABILITIES, DMA_PRESENT, 1, 0)
REG32(E_DREG_STATUS, 0x284)
    FIELD(E_DREG_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_DREG_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_DREG_CONTROL, 0x288)
    FIELD(E_DREG_CONTROL, DMA_SIZE, 2, 16)
    FIELD(E_DREG_CONTROL, DMA_SECURITY_ENABLE, 1, 2)
    FIELD(E_DREG_CONTROL, DMA_ENABLE, 1, 0)
REG32(E_DREG_BASE_LO, 0x290)
    FIELD(E_DREG_BASE_LO, DMA_BASE_LO, 20, 12)
REG32(E_DREG_BASE_HI, 0x294)
REG32(E_ESUB_CAPABILITIES, 0x2e0)
    FIELD(E_ESUB_CAPABILITIES, SUBTRACTIVE_DECODE_PRESENT, 1, 0)
REG32(E_ESUB_STATUS, 0x2e4)
    FIELD(E_ESUB_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(E_ESUB_STATUS, RD_PENDING_CTR, 9, 0)
REG32(E_ESUB_CONTROL, 0x2e8)
    FIELD(E_ESUB_CONTROL, EGRESS_SUB_ENABLE, 1, 0)
REG32(I_MSII_CAPABILITIES, 0x300)
    FIELD(I_MSII_CAPABILITIES, I_MSII_SIZE_MAX, 8, 24)
    FIELD(I_MSII_CAPABILITIES, I_MSII_SIZE_OFFSET, 8, 16)
    FIELD(I_MSII_CAPABILITIES, I_MSII_PRESENT, 1, 0)
REG32(I_MSII_CONTROL, 0x308)
    FIELD(I_MSII_CONTROL, I_MSII_SIZE, 5, 16)
    FIELD(I_MSII_CONTROL, I_MSII_STATUS_ENABLE, 1, 15)
    FIELD(I_MSII_CONTROL, I_MSII_ENABLE, 1, 0)
REG32(I_MSII_BASE_LO, 0x310)
    FIELD(I_MSII_BASE_LO, I_MSII_BASE_LO, 20, 12)
REG32(I_MSII_BASE_HI, 0x314)
REG32(I_MSIX_CAPABILITIES, 0x320)
    FIELD(I_MSIX_CAPABILITIES, I_MSIX_SIZE_MAX, 8, 24)
    FIELD(I_MSIX_CAPABILITIES, I_MSIX_SIZE_OFFSET, 8, 16)
    FIELD(I_MSIX_CAPABILITIES, I_MSIX_PRESENT, 1, 0)
REG32(I_MSIX_CONTROL, 0x328)
    FIELD(I_MSIX_CONTROL, I_MSIX_SIZE, 5, 16)
    FIELD(I_MSIX_CONTROL, I_MSIX_ENABLE, 1, 0)
REG32(I_MSIX_BASE_LO, 0x330)
    FIELD(I_MSIX_BASE_LO, I_MSIX_BASE_LO, 20, 12)
REG32(I_MSIX_BASE_HI, 0x334)
REG32(I_ISUB_CAPABILITIES, 0x3e0)
    FIELD(I_ISUB_CAPABILITIES, SUBTRACTIVE_DECODE_PRESENT, 1, 0)
REG32(I_ISUB_STATUS, 0x3e4)
    FIELD(I_ISUB_STATUS, WR_PENDING_CTR, 9, 16)
    FIELD(I_ISUB_STATUS, RD_PENDING_CTR, 9, 0)
REG32(I_ISUB_CONTROL, 0x3e8)
    FIELD(I_ISUB_CONTROL, INGRESS_SUB_ENABLE, 1, 0)
REG32(MSGF_MISC_STATUS, 0x400)
    FIELD(MSGF_MISC_STATUS, PCIE_CORE_EVENT, 16, 16)
    FIELD(MSGF_MISC_STATUS, EGRESS_ADDRESS_TRANSLATION_ERROR, 1, 7)
    FIELD(MSGF_MISC_STATUS, INGRESS_ADDRESS_TRANSLATION_ERROR, 1, 6)
    FIELD(MSGF_MISC_STATUS, MASTER_ERROR, 1, 5)
    FIELD(MSGF_MISC_STATUS, SLAVE_ERROR, 1, 4)
    FIELD(MSGF_MISC_STATUS, UNCORRECTABLE_WRITE_ERROR, 1, 3)
    FIELD(MSGF_MISC_STATUS, RX_MSG_OVERFLOW, 1, 1)
    FIELD(MSGF_MISC_STATUS, RX_MSG_AVAIL, 1, 0)
REG32(MSGF_MISC_MASK, 0x404)
    FIELD(MSGF_MISC_MASK, PCIE_CORE_EVENT_MASK, 16, 16)
    FIELD(MSGF_MISC_MASK, EGRESS_ADDRESS_TRANSLATION_ERROR_MASK, 1, 7)
    FIELD(MSGF_MISC_MASK, INGRESS_ADDRESS_TRANSLATION_ERROR_MASK, 1, 6)
    FIELD(MSGF_MISC_MASK, MASTER_ERROR_MASK, 1, 5)
    FIELD(MSGF_MISC_MASK, SLAVE_ERROR_MASK, 1, 4)
    FIELD(MSGF_MISC_MASK, UNCORRECTABLE_WRITE_ERROR_MASK, 1, 3)
    FIELD(MSGF_MISC_MASK, RX_MSG_OVERFLOW_MASK, 1, 1)
    FIELD(MSGF_MISC_MASK, RX_MSG_AVAIL_MASK, 1, 0)
REG32(MSGF_MISC_SLAVE_ID, 0x408)
    FIELD(MSGF_MISC_SLAVE_ID, SLAVE_ERROR_ID, 8, 0)
REG32(MSGF_MISC_MASTER_ID, 0x40c)
    FIELD(MSGF_MISC_MASTER_ID, MASTER_ERROR_ID, 8, 0)
REG32(MSGF_MISC_INGRESS_ID, 0x410)
    FIELD(MSGF_MISC_INGRESS_ID, INGRESS_ERROR_ID, 8, 0)
REG32(MSGF_MISC_EGRESS_ID, 0x414)
    FIELD(MSGF_MISC_EGRESS_ID, EGRESS_ERROR_ID, 8, 0)
REG32(MSGF_LEG_STATUS, 0x420)
    FIELD(MSGF_LEG_STATUS, MSGF_LEG_STATUS_INTD, 1, 3)
    FIELD(MSGF_LEG_STATUS, MSGF_LEG_STATUS_INTC, 1, 2)
    FIELD(MSGF_LEG_STATUS, MSGF_LEG_STATUS_INTB, 1, 1)
    FIELD(MSGF_LEG_STATUS, MSGF_LEG_STATUS_INTA, 1, 0)
REG32(MSGF_LEG_MASK, 0x424)
    FIELD(MSGF_LEG_MASK, MSGF_LEG_MASK_INTD, 1, 3)
    FIELD(MSGF_LEG_MASK, MSGF_LEG_MASK_INTC, 1, 2)
    FIELD(MSGF_LEG_MASK, MSGF_LEG_MASK_INTB, 1, 1)
    FIELD(MSGF_LEG_MASK, MSGF_LEG_MASK_INTA, 1, 0)
REG32(MSGF_MSI_STATUS_LO, 0x440)
REG32(MSGF_MSI_STATUS_HI, 0x444)
REG32(MSGF_MSI_MASK_LO, 0x448)
REG32(MSGF_MSI_MASK_HI, 0x44c)
REG32(MSGF_DMA_STATUS, 0x460)
    FIELD(MSGF_DMA_STATUS, MSGF_DMA_STATUS, 1, 0)
REG32(MSGF_DMA_MASK, 0x464)
    FIELD(MSGF_DMA_MASK, MSGF_DMA_MASK, 1, 0)
REG32(MSGF_RX_FIFO_LEVEL, 0x480)
    FIELD(MSGF_RX_FIFO_LEVEL, LEVEL, 8, 0)
REG32(MSGF_RX_FIFO_POP, 0x484)
    FIELD(MSGF_RX_FIFO_POP, POP, 1, 0)
REG32(MSGF_RX_FIFO_TYPE, 0x488)
    FIELD(MSGF_RX_FIFO_TYPE, REQUESTER_ID, 16, 16)
    FIELD(MSGF_RX_FIFO_TYPE, INTR_TYPE, 2, 0)
REG32(MSGF_RX_FIFO_MSG, 0x48c)
    FIELD(MSGF_RX_FIFO_MSG, MESSAGE_TAG, 8, 16)
    FIELD(MSGF_RX_FIFO_MSG, MESSAGE_CODE, 8, 8)
    FIELD(MSGF_RX_FIFO_MSG, MESSAGE_PAYLOAD_PRESENT, 1, 3)
    FIELD(MSGF_RX_FIFO_MSG, MESSAGE_ROUTING, 3, 0)
REG32(MSGF_RX_FIFO_ADDRESS_LO, 0x490)
REG32(MSGF_RX_FIFO_ADDRESS_HI, 0x494)
REG32(MSGF_RX_FIFO_DATA, 0x498)
REG32(TX_PCIE_IO_EXECUTE, 0x600)
    FIELD(TX_PCIE_IO_EXECUTE, IO_DONE_STATUS, 2, 24)
    FIELD(TX_PCIE_IO_EXECUTE, IO_DONE, 1, 16)
    FIELD(TX_PCIE_IO_EXECUTE, IO_BUSY, 1, 8)
    FIELD(TX_PCIE_IO_EXECUTE, IO_EXECUTE, 1, 0)
REG32(TX_PCIE_IO_CONTROL, 0x604)
    FIELD(TX_PCIE_IO_CONTROL, IO_BE, 4, 8)
    FIELD(TX_PCIE_IO_CONTROL, IO_TYPE, 1, 0)
REG32(TX_PCIE_IO_ADDRESS, 0x608)
    FIELD(TX_PCIE_IO_ADDRESS, IO_ADDRESS, 30, 2)
REG32(TX_PCIE_IO_DATA, 0x60c)
REG32(TX_PCIE_IO_DONE_DATA, 0x610)
REG32(TX_PCIE_MSG_EXECUTE, 0x620)
    FIELD(TX_PCIE_MSG_EXECUTE, MSG_DONE_STATUS, 2, 24)
    FIELD(TX_PCIE_MSG_EXECUTE, MSG_DONE, 1, 16)
    FIELD(TX_PCIE_MSG_EXECUTE, MSG_BUSY, 1, 8)
    FIELD(TX_PCIE_MSG_EXECUTE, MSG_EXECUTE, 1, 0)
REG32(TX_PCIE_MSG_CONTROL, 0x624)
    FIELD(TX_PCIE_MSG_CONTROL, MSG_HAS_DATA, 1, 24)
    FIELD(TX_PCIE_MSG_CONTROL, MSG_TAG, 8, 16)
    FIELD(TX_PCIE_MSG_CONTROL, MSG_CODE, 8, 8)
    FIELD(TX_PCIE_MSG_CONTROL, MSG_FMT_TYPE, 8, 0)
REG32(TX_PCIE_MSG_SPECIFIC_LO, 0x628)
    FIELD(TX_PCIE_MSG_SPECIFIC_LO, MSG_TLP_HDR11, 8, 24)
    FIELD(TX_PCIE_MSG_SPECIFIC_LO, MSG_TLP_HDR10, 8, 16)
    FIELD(TX_PCIE_MSG_SPECIFIC_LO, MSG_TLP_HDR9, 8, 8)
    FIELD(TX_PCIE_MSG_SPECIFIC_LO, MSG_TLP_HDR8, 8, 0)
REG32(TX_PCIE_MSG_SPECIFIC_HI, 0x62c)
    FIELD(TX_PCIE_MSG_SPECIFIC_HI, MSG_TLP_HDR15, 8, 24)
    FIELD(TX_PCIE_MSG_SPECIFIC_HI, MSG_TLP_HDR14, 8, 16)
    FIELD(TX_PCIE_MSG_SPECIFIC_HI, MSG_TLP_HDR13, 8, 8)
    FIELD(TX_PCIE_MSG_SPECIFIC_HI, MSG_TLP_HDR12, 8, 0)
REG32(TX_PCIE_MSG_DATA, 0x630)

#define R_MAX (R_TX_PCIE_MSG_DATA + 1)

typedef struct AXIPCIE_MAIN {
    PCIExpressHost parent_obj;
    MemoryRegion *dma_mr;
    AddressSpace *dma_as;
    MemTxAttrs *attr;

    MemoryRegion iommu_attr;
    AddressSpace *iommu_attr_as;

    MemoryRegion iomem;
    MemoryRegion io_ioport;
    MemoryRegion io_mmio;
    MemoryRegion io_msi;

    qemu_irq irq_legacy;
    qemu_irq irq_msi[2];

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} AXIPCIE_MAIN;

static void axipcie_main_update_irq(AXIPCIE_MAIN *s)
{
    bool legacy;

    legacy = s->regs[R_MSGF_LEG_STATUS] & s->regs[R_MSGF_LEG_MASK];
    qemu_set_irq(s->irq_legacy, legacy);
}

static void axipcie_set_irq(void *opaque, int irq_num, int level)
{
    AXIPCIE_MAIN *s = opaque;

    s->regs[R_MSGF_LEG_STATUS] &= ~(1 << irq_num);
    s->regs[R_MSGF_LEG_STATUS] |= (!!level) << irq_num;
    axipcie_main_update_irq(s);
}

static void legacy_mask_pw(RegisterInfo *reg, uint64_t val64)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(reg->opaque);
    axipcie_main_update_irq(s);
}

static void update_msi_irqs(AXIPCIE_MAIN *s)
{
    uint32_t p, m;

    p = s->regs[R_MSGF_MSI_STATUS_LO];
    m = s->regs[R_MSGF_MSI_MASK_LO];
    qemu_set_irq(s->irq_msi[0], p & m);

    p = s->regs[R_MSGF_MSI_STATUS_HI];
    m = s->regs[R_MSGF_MSI_MASK_HI];
    qemu_set_irq(s->irq_msi[1], p & m);
}

static void msi_update_pw(RegisterInfo *reg, uint64_t val64)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(reg->opaque);
    update_msi_irqs(s);
}

static void msi_mr_update(AXIPCIE_MAIN *s)
{
    bool msi_en = AF_EX32(s->regs, I_MSII_CONTROL, I_MSII_ENABLE);
    bool msix_en = AF_EX32(s->regs, I_MSIX_CONTROL, I_MSIX_ENABLE);
    memory_region_set_enabled(&s->io_msi, msi_en || msix_en);
}

static void msi_mr_pw(RegisterInfo *reg, uint64_t val64)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(reg->opaque);
    msi_mr_update(s);
}

static RegisterAccessInfo axipcie_main_regs_info[] = {
    {   .name = "BRIDGE_CORE_CFG_PCIE_RX0",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_RX0,
        .reset = 0x10000,
        .rsvd = 0xfffcfff8,
        .ro = 0xfffcfff8,
    },{ .name = "BRIDGE_CORE_CFG_PCIE_RX1",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_RX1,
        .rsvd = 0xfffffe00,
        .ro = 0xfffffe00,
    },{ .name = "BRIDGE_CORE_CFG_AXI_MASTER",
        .decode.addr = A_BRIDGE_CORE_CFG_AXI_MASTER,
        .rsvd = 0xffffff88,
        .ro = 0xffffff88,
    },{ .name = "BRIDGE_CORE_CFG_PCIE_TX",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_TX,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "BRIDGE_CORE_CFG_INTERRUPT",
        .decode.addr = A_BRIDGE_CORE_CFG_INTERRUPT,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "BRIDGE_CORE_CFG_RAM_DISABLE0",
        .decode.addr = A_BRIDGE_CORE_CFG_RAM_DISABLE0,
        .rsvd = 0xffff8680,
        .ro = 0xffff8680,
    },{ .name = "BRIDGE_CORE_CFG_RAM_DISABLE1",
        .decode.addr = A_BRIDGE_CORE_CFG_RAM_DISABLE1,
        .rsvd = 0xffff8680,
        .ro = 0xffff8680,
    },{ .name = "BRIDGE_CORE_CFG_PCIE_RELAXED_ORDER",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_RELAXED_ORDER,
        .reset = 0x3,
        .rsvd = 0xfffffffc,
        .ro = 0xfffffffc,
    },{ .name = "BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_RX_MSG_FILTER,
        .rsvd = 0x1f51,
        .ro = 0x1f51,
    },{ .name = "BRIDGE_CORE_CFG_RQ_REQ_ORDER",
        .decode.addr = A_BRIDGE_CORE_CFG_RQ_REQ_ORDER,
        .rsvd = 0x3fff0000,
        .ro = 0x3fff0000,
    },{ .name = "BRIDGE_CORE_CFG_PCIE_CREDIT",
        .decode.addr = A_BRIDGE_CORE_CFG_PCIE_CREDIT,
        .reset = 0x200200,
        .rsvd = 0x1f00f000,
        .ro = 0x1f00f000,
    },{ .name = "BRIDGE_CORE_CFG_AXI_M_W_TICK_COUNT",
        .decode.addr = A_BRIDGE_CORE_CFG_AXI_M_W_TICK_COUNT,
        .reset = 0xbea,
        .rsvd = 0xffff0000,
        .ro = 0xffff0000,
    },{ .name = "BRIDGE_CORE_CFG_AXI_M_R_TICK_COUNT",
        .decode.addr = A_BRIDGE_CORE_CFG_AXI_M_R_TICK_COUNT,
        .reset = 0xbea,
        .rsvd = 0xffff0000,
        .ro = 0xffff0000,
    },{ .name = "BRIDGE_CORE_CFG_CRS_RPL_TICK_COUNT",
        .decode.addr = A_BRIDGE_CORE_CFG_CRS_RPL_TICK_COUNT,
        .reset = 0x2210,
        .rsvd = 0xffff0000,
        .ro = 0xffff0000,
    },{ .name = "E_BREG_CAPABILITIES",  .decode.addr = A_E_BREG_CAPABILITIES,
        .reset = 0x30c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "E_BREG_STATUS",  .decode.addr = A_E_BREG_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_BREG_CONTROL",  .decode.addr = A_E_BREG_CONTROL,
        .reset = 0x2,
        .rsvd = 0xfffcfff8,
        .ro = 0xfffcfff8,
    },{ .name = "E_BREG_BASE_LO",  .decode.addr = A_E_BREG_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "E_BREG_BASE_HI",  .decode.addr = A_E_BREG_BASE_HI,
    },{ .name = "E_ECAM_CAPABILITIES",  .decode.addr = A_E_ECAM_CAPABILITIES,
        .reset = 0x100c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "E_ECAM_STATUS",  .decode.addr = A_E_ECAM_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_ECAM_CONTROL",  .decode.addr = A_E_ECAM_CONTROL,
        .rsvd = 0xffe0fffa,
        .ro = 0xffe0fffa,
    },{ .name = "E_ECAM_BASE_LO",  .decode.addr = A_E_ECAM_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "E_ECAM_BASE_HI",  .decode.addr = A_E_ECAM_BASE_HI,
    },{ .name = "E_MSXT_CAPABILITIES",  .decode.addr = A_E_MSXT_CAPABILITIES,
        .reset = 0x30c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "E_MSXT_STATUS",  .decode.addr = A_E_MSXT_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_MSXT_CONTROL",  .decode.addr = A_E_MSXT_CONTROL,
        .rsvd = 0xfffcfffa,
        .ro = 0xfffcfffa,
    },{ .name = "E_MSXT_BASE_LO",  .decode.addr = A_E_MSXT_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "E_MSXT_BASE_HI",  .decode.addr = A_E_MSXT_BASE_HI,
    },{ .name = "E_MSXP_CAPABILITIES",  .decode.addr = A_E_MSXP_CAPABILITIES,
        .reset = 0x30c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "E_MSXP_STATUS",  .decode.addr = A_E_MSXP_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_MSXP_CONTROL",  .decode.addr = A_E_MSXP_CONTROL,
        .rsvd = 0xfffcfffa,
        .ro = 0xfffcfffa,
    },{ .name = "E_MSXP_BASE_LO",  .decode.addr = A_E_MSXP_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "E_MSXP_BASE_HI",  .decode.addr = A_E_MSXP_BASE_HI,
    },{ .name = "E_DREG_CAPABILITIES",  .decode.addr = A_E_DREG_CAPABILITIES,
        .reset = 0x30c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "E_DREG_STATUS",  .decode.addr = A_E_DREG_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_DREG_CONTROL",  .decode.addr = A_E_DREG_CONTROL,
        .rsvd = 0xfffcfffa,
        .ro = 0xfffcfffa,
    },{ .name = "E_DREG_BASE_LO",  .decode.addr = A_E_DREG_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "E_DREG_BASE_HI",  .decode.addr = A_E_DREG_BASE_HI,
    },{ .name = "E_ESUB_CAPABILITIES",  .decode.addr = A_E_ESUB_CAPABILITIES,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xffffffff,
    },{ .name = "E_ESUB_STATUS",  .decode.addr = A_E_ESUB_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "E_ESUB_CONTROL",  .decode.addr = A_E_ESUB_CONTROL,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "I_MSII_CAPABILITIES",  .decode.addr = A_I_MSII_CAPABILITIES,
        .reset = 0x1f0c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "I_MSII_CONTROL",  .decode.addr = A_I_MSII_CONTROL,
        .rsvd = 0xffe07ffe,
        .ro = 0xffe07ffe,
        .post_write = msi_mr_pw,
    },{ .name = "I_MSII_BASE_LO",  .decode.addr = A_I_MSII_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "I_MSII_BASE_HI",  .decode.addr = A_I_MSII_BASE_HI,
    },{ .name = "I_MSIX_CAPABILITIES",  .decode.addr = A_I_MSIX_CAPABILITIES,
        .reset = 0x1f0c0001,
        .rsvd = 0xfffe,
        .ro = 0xffffffff,
    },{ .name = "I_MSIX_CONTROL",  .decode.addr = A_I_MSIX_CONTROL,
        .rsvd = 0xffe0fffe,
        .ro = 0xffe0fffe,
        .post_write = msi_mr_pw,
    },{ .name = "I_MSIX_BASE_LO",  .decode.addr = A_I_MSIX_BASE_LO,
        .rsvd = 0xfff,
        .ro = 0xfff,
    },{ .name = "I_MSIX_BASE_HI",  .decode.addr = A_I_MSIX_BASE_HI,
    },{ .name = "I_ISUB_CAPABILITIES",  .decode.addr = A_I_ISUB_CAPABILITIES,
        .reset = 0x1,
        .rsvd = 0xfffffffe,
        .ro = 0xffffffff,
    },{ .name = "I_ISUB_STATUS",  .decode.addr = A_I_ISUB_STATUS,
        .rsvd = 0xfe00fe00,
        .ro = 0xffffffff,
    },{ .name = "I_ISUB_CONTROL",  .decode.addr = A_I_ISUB_CONTROL,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "MSGF_MISC_STATUS",  .decode.addr = A_MSGF_MISC_STATUS,
        .rsvd = 0xff04,
        .ro = 0xff04,
        .w1c = 0xffff00fb,
    },{ .name = "MSGF_MISC_MASK",  .decode.addr = A_MSGF_MISC_MASK,
        .rsvd = 0xff04,
        .ro = 0xff04,
    },{ .name = "MSGF_MISC_SLAVE_ID",  .decode.addr = A_MSGF_MISC_SLAVE_ID,
        .rsvd = 0xffffff00,
        .ro = 0xffffffff,
    },{ .name = "MSGF_MISC_MASTER_ID",  .decode.addr = A_MSGF_MISC_MASTER_ID,
        .rsvd = 0xffffff00,
        .ro = 0xffffffff,
    },{ .name = "MSGF_MISC_INGRESS_ID",  .decode.addr = A_MSGF_MISC_INGRESS_ID,
        .rsvd = 0xffffff00,
        .ro = 0xffffffff,
    },{ .name = "MSGF_MISC_EGRESS_ID",  .decode.addr = A_MSGF_MISC_EGRESS_ID,
        .rsvd = 0xffffff00,
        .ro = 0xffffffff,
    },{ .name = "MSGF_LEG_STATUS",  .decode.addr = A_MSGF_LEG_STATUS,
        .rsvd = 0xfffffff0,
        .ro = 0xffffffff,
    },{ .name = "MSGF_LEG_MASK",  .decode.addr = A_MSGF_LEG_MASK,
        .rsvd = 0xfffffff0,
        .ro = 0xfffffff0,
        .post_write = legacy_mask_pw,
    },{ .name = "MSGF_MSI_STATUS_LO",  .decode.addr = A_MSGF_MSI_STATUS_LO,
        .w1c = 0xffffffff,
        .post_write = msi_update_pw,
    },{ .name = "MSGF_MSI_STATUS_HI",  .decode.addr = A_MSGF_MSI_STATUS_HI,
        .w1c = 0xffffffff,
        .post_write = msi_update_pw,
    },{ .name = "MSGF_MSI_MASK_LO",  .decode.addr = A_MSGF_MSI_MASK_LO,
        .post_write = msi_update_pw,
    },{ .name = "MSGF_MSI_MASK_HI",  .decode.addr = A_MSGF_MSI_MASK_HI,
        .post_write = msi_update_pw,
    },{ .name = "MSGF_DMA_STATUS",  .decode.addr = A_MSGF_DMA_STATUS,
        .rsvd = 0xfffffffe,
        .ro = 0xffffffff,
    },{ .name = "MSGF_DMA_MASK",  .decode.addr = A_MSGF_DMA_MASK,
        .rsvd = 0xfffffffe,
        .ro = 0xfffffffe,
    },{ .name = "MSGF_RX_FIFO_LEVEL",  .decode.addr = A_MSGF_RX_FIFO_LEVEL,
        .rsvd = 0xffffff00,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_POP",  .decode.addr = A_MSGF_RX_FIFO_POP,
        .rsvd = 0xfffffffe,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_TYPE",  .decode.addr = A_MSGF_RX_FIFO_TYPE,
        .rsvd = 0xfffc,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_MSG",  .decode.addr = A_MSGF_RX_FIFO_MSG,
        .rsvd = 0xff0000f0,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_ADDRESS_LO",
        .decode.addr = A_MSGF_RX_FIFO_ADDRESS_LO,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_ADDRESS_HI",
        .decode.addr = A_MSGF_RX_FIFO_ADDRESS_HI,
        .ro = 0xffffffff,
    },{ .name = "MSGF_RX_FIFO_DATA",  .decode.addr = A_MSGF_RX_FIFO_DATA,
        .ro = 0xffffffff,
    },{ .name = "TX_PCIE_IO_EXECUTE",  .decode.addr = A_TX_PCIE_IO_EXECUTE,
        .rsvd = 0xfcfefefe,
        .ro = 0xffffffff,
    },{ .name = "TX_PCIE_IO_CONTROL",  .decode.addr = A_TX_PCIE_IO_CONTROL,
        .rsvd = 0xfffff0fe,
        .ro = 0xfffff0fe,
    },{ .name = "TX_PCIE_IO_ADDRESS",  .decode.addr = A_TX_PCIE_IO_ADDRESS,
        .rsvd = 0x3,
        .ro = 0x3,
    },{ .name = "TX_PCIE_IO_DATA",  .decode.addr = A_TX_PCIE_IO_DATA,
    },{ .name = "TX_PCIE_IO_DONE_DATA",
        .decode.addr = A_TX_PCIE_IO_DONE_DATA,
        .ro = 0xffffffff,
    },{ .name = "TX_PCIE_MSG_EXECUTE",  .decode.addr = A_TX_PCIE_MSG_EXECUTE,
        .rsvd = 0xfcfefefe,
        .ro = 0xffffffff,
    },{ .name = "TX_PCIE_MSG_CONTROL",  .decode.addr = A_TX_PCIE_MSG_CONTROL,
        .rsvd = 0xfe000000,
        .ro = 0xfe000000,
    },{ .name = "TX_PCIE_MSG_SPECIFIC_LO",
        .decode.addr = A_TX_PCIE_MSG_SPECIFIC_LO,
    },{ .name = "TX_PCIE_MSG_SPECIFIC_HI",
        .decode.addr = A_TX_PCIE_MSG_SPECIFIC_HI,
    },{ .name = "TX_PCIE_MSG_DATA",  .decode.addr = A_TX_PCIE_MSG_DATA,
    }
};

static void axipcie_main_reset(DeviceState *dev)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    msi_mr_update(s);
}

static uint64_t axipcie_main_read(void *opaque, hwaddr addr, unsigned size)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: read from %" HWADDR_PRIx "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr);
        return 0;
    }
    return register_read(r);
}

static void axipcie_main_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(opaque);
    RegisterInfo *r = &s->regs_info[addr / 4];

    if (!r->data) {
        qemu_log("%s: Decode error: write to %" HWADDR_PRIx "=%" PRIx64 "\n",
                 object_get_canonical_path(OBJECT(s)),
                 addr, value);
        return;
    }
    register_write(r, value, ~0);
}

static const MemoryRegionOps axipcie_main_ops = {
    .read = axipcie_main_read,
    .write = axipcie_main_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};


static uint64_t axipcie_msi_read(void *opaque, hwaddr addr, unsigned size)
{
    return 0;
}

static void axipcie_msi_write(void *opaque, hwaddr addr, uint64_t value,
                      unsigned size)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(opaque);
    unsigned int irq = value & 63;

    if (irq < 32) {
        s->regs[R_MSGF_MSI_STATUS_LO] |= 1 << irq;
    } else {
        s->regs[R_MSGF_MSI_STATUS_HI] |= 1 << (irq - 32);
    }
    update_msi_irqs(s);
}

static const MemoryRegionOps axipcie_msi_ops = {
    .read = axipcie_msi_read,
    .write = axipcie_msi_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static IOMMUTLBEntry axipcie_translate(MemoryRegion *mr, hwaddr addr,
                                       bool is_write, MemTxAttrs *attr)
{
    AXIPCIE_MAIN *s = container_of(mr, AXIPCIE_MAIN, iommu_attr);
    IOMMUTLBEntry ret = {
        .iova = addr,
        .translated_addr = addr,
        .addr_mask = ~(hwaddr)0,
        .perm = IOMMU_RW,
        .target_as = s->dma_as,
    };

    if (s->attr) {
        *attr = *s->attr;
    }
    return ret;
}

static const MemoryRegionIOMMUOps axipcie_iommu_ops = {
    .translate_attr = axipcie_translate,
};

static AddressSpace *axipcie_dma_as(PCIBus *bus, void *opaque, int devfn)
{
    return opaque;
}

static void axipcie_main_realize(DeviceState *dev, Error **errp)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(dev);
    PCIHostState *pci = PCI_HOST_BRIDGE(dev);
    PCIExpressHost *pex = PCIE_HOST_BRIDGE(dev);
    SysBusDevice *sbd = SYS_BUS_DEVICE(dev);
    const char *prefix = object_get_canonical_path(OBJECT(dev));
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(axipcie_main_regs_info); ++i) {
        RegisterInfo *r;

        r = &s->regs_info[axipcie_main_regs_info[i].decode.addr / 4];
        *r = (RegisterInfo) {
            .data = (uint8_t *)&s->regs[
                    axipcie_main_regs_info[i].decode.addr / 4],
            .data_size = sizeof(uint32_t),
            .access = &axipcie_main_regs_info[i],
            .debug = XILINX_AXIPCIE_MAIN_ERR_DEBUG,
            .prefix = prefix,
            .opaque = s,
        };
    }

    assert(s->dma_mr);
    s->dma_as = s->dma_mr ? address_space_init_shareable(s->dma_mr, NULL)
                          : &address_space_memory;

    pcie_host_mmcfg_init(pex, PCIE_MMCFG_SIZE_MAX);
    memory_region_init(&s->io_mmio, OBJECT(s), "mmio", UINT64_MAX);
    /* Xilinx PCIe does not support memory-mapped legacy I/O. We
     * create a dummy MR to please pci_register_bus().  */
    memory_region_init(&s->io_ioport, OBJECT(s), "ioport", 64 * 1024);

    sysbus_init_mmio(sbd, &pex->mmio);
    sysbus_init_mmio(sbd, &s->io_mmio);
    sysbus_init_irq(sbd, &s->irq_legacy);
    sysbus_init_irq(sbd, &s->irq_msi[0]);
    sysbus_init_irq(sbd, &s->irq_msi[1]);

    pci->bus = pci_register_bus(dev, "pcie.0", axipcie_set_irq,
                                pci_swizzle_map_irq_fn, s, &s->io_mmio,
                                &s->io_ioport, PCI_DEVFN(0, 0), 4,
                                TYPE_PCIE_BUS);

    memory_region_init_iommu(&s->iommu_attr, OBJECT(s), &axipcie_iommu_ops,
                             "axipcie-attr-iommu", UINT64_MAX);
    s->iommu_attr_as = address_space_init_shareable(&s->iommu_attr, NULL);

    pci_setup_iommu(pci->bus, axipcie_dma_as, s->iommu_attr_as);
}

static void axipcie_main_init(Object *obj)
{
    AXIPCIE_MAIN *s = XILINX_AXIPCIE_MAIN(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    memory_region_init_io(&s->iomem, obj, &axipcie_main_ops, s,
                          TYPE_XILINX_AXIPCIE_MAIN, R_MAX * 4);
    memory_region_init_io(&s->io_msi, obj, &axipcie_msi_ops, s,
                          "axipcie-msi", 0x100);
    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_mmio(sbd, &s->io_msi);
    msi_nonbroken = true;

    object_property_add_link(obj, "dma", TYPE_MEMORY_REGION,
                             (Object **)&s->dma_mr,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
    object_property_add_link(obj, "memattr", TYPE_MEMORY_TRANSACTION_ATTR,
                             (Object **)&s->attr,
                             qdev_prop_allow_set_link_before_realize,
                             OBJ_PROP_LINK_UNREF_ON_RELEASE,
                             &error_abort);
}

static const VMStateDescription vmstate_axipcie_main = {
    .name = TYPE_XILINX_AXIPCIE_MAIN,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, AXIPCIE_MAIN, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static const char *axipcie_main_host_root_bus_path(PCIHostState *host_bridge,
                                                   PCIBus *rootbus)
{
    return "0000:00";
}

static void axipcie_main_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    PCIHostBridgeClass *hc = PCI_HOST_BRIDGE_CLASS(klass);

    dc->reset = axipcie_main_reset;
    dc->realize = axipcie_main_realize;
    dc->vmsd = &vmstate_axipcie_main;

    hc->root_bus_path = axipcie_main_host_root_bus_path;
}

static const TypeInfo axipcie_main_info = {
    .name          = TYPE_XILINX_AXIPCIE_MAIN,
    .parent        = TYPE_PCIE_HOST_BRIDGE,
    .instance_size = sizeof(AXIPCIE_MAIN),
    .class_init    = axipcie_main_class_init,
    .instance_init = axipcie_main_init,
};

static void axipcie_main_register_types(void)
{
    type_register_static(&axipcie_main_info);
}

type_init(axipcie_main_register_types)
