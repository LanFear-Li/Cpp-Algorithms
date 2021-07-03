//
// Created by LanFear on 2021/6/21.
//

#include "A.h"

A_stm A_compound(A_stm stm1, A_stm stm2) {
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_compoundStm;
    s->u.compound.stm1 = stm1, s->u.compound.stm2 = stm2;
    return s;
}

A_stm A_AssignStm(string id, A_exp exp) {
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_assignStm;
    s->u.assign.id = id, s->u.assign.exp = exp;
    return s;
}

A_stm A_PrintStm(A_exp_list exps) {
    A_stm s = checked_malloc(sizeof(*s));
    s->kind = A_printStm;
    s->u.print.list = exps;
    return s;
}

A_stm stmConstructor() {
    A_stm prog = A_CompoundStm(
            A_AssignStm(
                    "a",
                    A_OpExp(
                            A_NumExp(5),
                            A_plus,
                            A_NumExp(3))),
            A_CompoundStm(
                    A_AssignStm(
                            "b",
                            A_EseqExp(
                                    A_PrintStm(
                                            A_PairExpList(
                                                    A_IdExp("a"),
                                                    A_LastExpList(
                                                            A_OpExp(
                                                                    A_IdExp("a"),
                                                                    A_minus,
                                                                    A_NumExp(1))))),
                                    A_OpExp(
                                            A_NumExp(10),
                                            A_times,
                                            A_IdExp("a")))),
                    A_PrintStm(
                            A_LastExpList(
                                    A_IdExp("b")))));
    return prog;
}

int maxargs(A_stm stm) {
    if (stm->kind == )
}