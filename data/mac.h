// 'M' extension means we require integer mul/div standard extension.
require_extension('M');
// RD = RD + RS1 * RS2
reg_t tmp = sext_xlen(RS1 * RS2);
WRITE_RD(sext_xlen(READ_REG(insn.rd()) + tmp));