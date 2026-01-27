	.file	"NHAT.cpp"
	.text
	.p2align 4
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
__tcf_1:
	pushq	%rbx
	subq	$32, %rsp
	movq	16+memo(%rip), %rbx
	testq	%rbx, %rbx
	je	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	movq	%rbx, %rcx
	movq	(%rbx), %rbx
	call	_ZdlPv
	testq	%rbx, %rbx
	jne	.L3
.L2:
	movq	8+memo(%rip), %r8
	movq	memo(%rip), %rcx
	xorl	%edx, %edx
	salq	$3, %r8
	call	memset
	movq	memo(%rip), %rcx
	leaq	48+memo(%rip), %rax
	movq	$0, 24+memo(%rip)
	movq	$0, 16+memo(%rip)
	cmpq	%rax, %rcx
	je	.L1
	addq	$32, %rsp
	popq	%rbx
	jmp	_ZdlPv
	.p2align 4,,10
	.p2align 3
.L1:
	addq	$32, %rsp
	popq	%rbx
	ret
	.p2align 4
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
__tcf_0:
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.def	__gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.section	.text$_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy
	.def	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy;	.scl	2;	.type	32;	.endef
_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy:
	leaq	8(%rsp), %r10
	andq	$-16, %rsp
	pushq	-8(%r10)
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r10
	pushq	%rsi
	leaq	-144(%rbp), %rax
	leaq	.L24(%rip), %rsi
	pushq	%rbx
	leaq	__gxx_personality_sj0(%rip), %rbx
	subq	$184, %rsp
	movq	%rbx, -96(%rbp)
	leaq	.LLSDA3035(%rip), %rbx
	movq	%rbx, -88(%rbp)
	leaq	-32(%rbp), %rbx
	movq	%rcx, -40(%rbp)
	movq	%rax, %rcx
	movq	%rdx, -152(%rbp)
	movq	%r8, -160(%rbp)
	movq	%rbx, -80(%rbp)
	movq	%rsi, -72(%rbp)
	movq	%rsp, -64(%rbp)
	movq	%rax, -168(%rbp)
	call	_Unwind_SjLj_Register
	cmpq	$1, -152(%rbp)
	je	.L35
	movabsq	$1152921504606846975, %rax
	cmpq	%rax, -152(%rbp)
	ja	.L36
	movq	-152(%rbp), %rax
	movl	$1, -136(%rbp)
	salq	$3, %rax
	movq	%rax, %rcx
	movq	%rax, -176(%rbp)
	call	_Znwy
	movq	-176(%rbp), %r8
	xorl	%edx, %edx
	movq	%rax, %rcx
	movq	%rax, -160(%rbp)
	call	memset
	movq	-40(%rbp), %rax
	leaq	48(%rax), %r11
.L14:
	movq	-40(%rbp), %rax
	movq	16(%rax), %r8
	movq	$0, 16(%rax)
	testq	%r8, %r8
	je	.L16
	xorl	%r10d, %r10d
	leaq	16(%rax), %rbx
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L18:
	movq	(%rax), %rax
	movq	%rax, (%rcx)
	movq	(%r9), %rax
	movq	%rcx, (%rax)
.L19:
	testq	%r8, %r8
	je	.L16
.L17:
	movq	%r8, %rcx
	xorl	%edx, %edx
	movq	(%r8), %r8
	movq	8(%rcx), %rax
	divq	-152(%rbp)
	movq	-160(%rbp), %rax
	leaq	(%rax,%rdx,8), %r9
	movq	(%r9), %rax
	testq	%rax, %rax
	jne	.L18
	movq	-40(%rbp), %rsi
	movq	16(%rsi), %rax
	movq	%rax, (%rcx)
	movq	%rcx, 16(%rsi)
	movq	%rbx, (%r9)
	cmpq	$0, (%rcx)
	je	.L23
	movq	-160(%rbp), %rax
	movq	%rcx, (%rax,%r10,8)
	movq	%rdx, %r10
	testq	%r8, %r8
	jne	.L17
	.p2align 4,,10
	.p2align 3
.L16:
	movq	-40(%rbp), %rax
	movq	(%rax), %rcx
	cmpq	%r11, %rcx
	je	.L20
	call	_ZdlPv
.L20:
	movq	-40(%rbp), %rax
	movq	-160(%rbp), %rbx
	movq	-152(%rbp), %rdx
	movq	-168(%rbp), %rcx
	movq	%rbx, (%rax)
	movq	%rdx, 8(%rax)
	call	_Unwind_SjLj_Unregister
	addq	$184, %rsp
	popq	%rbx
	popq	%rsi
	popq	%r10
	popq	%rbp
	leaq	-8(%r10), %rsp
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	movq	%rdx, %r10
	jmp	.L19
	.p2align 4,,10
	.p2align 3
.L35:
	movq	-40(%rbp), %rax
	movq	$0, 48(%rax)
	addq	$48, %rax
	movq	%rax, -160(%rbp)
	movq	%rax, %r11
	jmp	.L14
.L36:
	movl	$1, -136(%rbp)
	call	_ZSt17__throw_bad_allocv
.L24:
	addq	$32, %rbp
	movq	-128(%rbp), %rax
	movq	%rax, -152(%rbp)
	movl	-136(%rbp), %eax
	testl	%eax, %eax
	jne	.L37
	movq	-152(%rbp), %rcx
	call	__cxa_begin_catch
	movq	-160(%rbp), %rax
	movq	-40(%rbp), %rbx
	movq	(%rax), %rax
	movq	%rax, 40(%rbx)
	movl	$2, -136(%rbp)
	call	__cxa_rethrow
.L37:
	subl	$1, %eax
	jne	.L38
	movl	$0, -136(%rbp)
	call	__cxa_end_catch
	movq	-152(%rbp), %rcx
	movl	$-1, -136(%rbp)
	call	_Unwind_SjLj_Resume
.L38:
	ud2
	.section	.gcc_except_table,"w"
	.align 4
.LLSDA3035:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT3035-.LLSDATTD3035
.LLSDATTD3035:
	.byte	0x1
	.uleb128 .LLSDACSE3035-.LLSDACSB3035
.LLSDACSB3035:
	.uleb128 0
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0
.LLSDACSE3035:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT3035:
	.section	.text$_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy,"x"
	.linkonce discard
	.section	.text$_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_,"x"
	.linkonce discard
	.align 2
	.p2align 4
	.globl	_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	.def	_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_;	.scl	2;	.type	32;	.endef
_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_:
	leaq	8(%rsp), %r10
	andq	$-16, %rsp
	leaq	.LLSDA2898(%rip), %r8
	pushq	-8(%r10)
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%r10
	leaq	__gxx_personality_sj0(%rip), %r10
	leaq	-160(%rbp), %rax
	leaq	-16(%rbp), %r9
	subq	$248, %rsp
	movq	%r10, -112(%rbp)
	leaq	.L52(%rip), %r10
	movq	%rcx, -56(%rbp)
	movq	%rax, %rcx
	movq	%rdx, -168(%rbp)
	movq	%r9, -96(%rbp)
	movq	%rax, -184(%rbp)
	movq	%r8, -104(%rbp)
	movq	%r10, -88(%rbp)
	movq	%rsp, -80(%rbp)
	call	_Unwind_SjLj_Register
	movq	-56(%rbp), %r11
	movq	-168(%rbp), %rax
	xorl	%edx, %edx
	movq	(%rax), %rax
	movq	8(%r11), %rcx
	movq	%rax, -176(%rbp)
	divq	%rcx
	leaq	0(,%rdx,8), %rax
	movq	%rax, -192(%rbp)
	movq	(%r11), %rax
	movq	(%rax,%rdx,8), %r9
	testq	%r9, %r9
	je	.L40
	movq	(%r9), %rax
	movq	%rdx, %r10
	movq	8(%rax), %r8
	jmp	.L42
	.p2align 4,,10
	.p2align 3
.L69:
	movq	(%rax), %r11
	testq	%r11, %r11
	je	.L40
	movq	8(%r11), %r8
	movq	%rax, %r9
	xorl	%edx, %edx
	movq	%r8, %rax
	divq	%rcx
	cmpq	%rdx, %r10
	jne	.L40
	movq	%r11, %rax
.L42:
	cmpq	%r8, -176(%rbp)
	jne	.L69
	movq	(%r9), %rax
	testq	%rax, %rax
	je	.L40
	addq	$16, %rax
	movq	%rax, -56(%rbp)
.L39:
	movq	-184(%rbp), %rcx
	call	_Unwind_SjLj_Unregister
	movq	-56(%rbp), %rax
	addq	$248, %rsp
	popq	%r10
	popq	%rbp
	leaq	-8(%r10), %rsp
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	movl	$-1, -152(%rbp)
	movl	$24, %ecx
	call	_Znwy
	movq	-56(%rbp), %rdx
	movq	$0, (%rax)
	movq	%rax, %rcx
	movq	%rax, -200(%rbp)
	movq	-168(%rbp), %rax
	movq	$0, 16(%rcx)
	movq	(%rax), %rax
	movq	%rax, 8(%rcx)
	movq	40(%rdx), %rax
	leaq	-48(%rbp), %rcx
	movq	%rax, -24(%rbp)
	movq	%rdx, %rax
	leaq	32(%rdx), %rdx
	movq	$1, 32(%rsp)
	movq	24(%rax), %r9
	movq	%rax, -56(%rbp)
	movq	8(%rax), %r8
	call	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEyyy
	cmpb	$0, -48(%rbp)
	movq	-40(%rbp), %rdx
	je	.L43
	movl	$2, -152(%rbp)
	movq	-56(%rbp), %rcx
	leaq	-24(%rbp), %r8
	call	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEyRKy
	movq	-56(%rbp), %rcx
	movq	-176(%rbp), %rax
	xorl	%edx, %edx
	divq	8(%rcx)
	leaq	0(,%rdx,8), %rax
	movq	%rax, -192(%rbp)
.L43:
	movq	-56(%rbp), %rax
	movq	-192(%rbp), %rcx
	movq	(%rax), %r8
	addq	%r8, %rcx
	movq	(%rcx), %rax
	testq	%rax, %rax
	je	.L44
	movq	(%rax), %rax
	movq	-200(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	(%rcx), %rax
	movq	%rdx, (%rax)
.L45:
	movq	-56(%rbp), %rax
	addq	$1, 24(%rax)
	movq	-200(%rbp), %rax
	addq	$16, %rax
	movq	%rax, -56(%rbp)
	jmp	.L39
	.p2align 4,,10
	.p2align 3
.L44:
	movq	-56(%rbp), %rdx
	movq	-200(%rbp), %r10
	movq	16(%rdx), %rax
	movq	%r10, 16(%rdx)
	movq	%rax, (%r10)
	testq	%rax, %rax
	je	.L46
	movq	8(%rax), %rax
	movq	%rdx, %r9
	xorl	%edx, %edx
	divq	8(%r9)
	movq	%r10, (%r8,%rdx,8)
.L46:
	movq	-56(%rbp), %rax
	addq	$16, %rax
	movq	%rax, (%rcx)
	jmp	.L45
.L52:
	addq	$16, %rbp
	movq	-144(%rbp), %rax
	movq	%rax, -56(%rbp)
	movl	-152(%rbp), %eax
	testl	%eax, %eax
	jne	.L70
	call	__cxa_end_catch
	movq	-56(%rbp), %rcx
	movl	$-1, -152(%rbp)
	call	_Unwind_SjLj_Resume
.L70:
	subl	$1, %eax
	jne	.L71
	movq	-56(%rbp), %rcx
	call	__cxa_begin_catch
	movq	-200(%rbp), %rcx
	call	_ZdlPv
	movl	$1, -152(%rbp)
	call	__cxa_rethrow
.L71:
	ud2
	.section	.gcc_except_table,"w"
	.align 4
.LLSDA2898:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT2898-.LLSDATTD2898
.LLSDATTD2898:
	.byte	0x1
	.uleb128 .LLSDACSE2898-.LLSDACSB2898
.LLSDACSB2898:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0x1
.LLSDACSE2898:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT2898:
	.section	.text$_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_,"x"
	.linkonce discard
	.text
	.p2align 4
	.globl	_Z1fx
	.def	_Z1fx;	.scl	2;	.type	32;	.endef
_Z1fx:
	pushq	%rsi
	movq	%rcx, %r8
	pushq	%rbx
	subq	$40, %rsp
	movq	%rcx, 64(%rsp)
	cmpq	$1, %rcx
	je	.L72
	movq	8+memo(%rip), %r10
	movq	%rcx, %rax
	xorl	%edx, %edx
	divq	%r10
	movq	memo(%rip), %rax
	movq	(%rax,%rdx,8), %rax
	movq	%rdx, %rbx
	testq	%rax, %rax
	je	.L74
	movq	(%rax), %rcx
	testq	%rcx, %rcx
	je	.L74
	movq	8(%rcx), %r9
	xorl	%r11d, %r11d
	jmp	.L79
	.p2align 4,,10
	.p2align 3
.L75:
	testq	%r11, %r11
	jne	.L77
	movq	(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L78
.L98:
	movq	8(%rcx), %r9
	xorl	%edx, %edx
	movq	%r9, %rax
	divq	%r10
	cmpq	%rdx, %rbx
	jne	.L78
.L79:
	cmpq	%r9, %r8
	jne	.L75
	movq	(%rcx), %rcx
	addq	$1, %r11
	testq	%rcx, %rcx
	jne	.L98
	.p2align 4,,10
	.p2align 3
.L78:
	testq	%r11, %r11
	jne	.L77
.L74:
	movq	%r8, %rcx
	shrq	$63, %rcx
	addq	%r8, %rcx
	sarq	%rcx
	andl	$1, %r8d
	jne	.L80
	call	_Z1fx
	leaq	64(%rsp), %rdx
	leaq	memo(%rip), %rcx
	movq	%rax, %rbx
	call	_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	leaq	1(%rbx), %r8
	movq	%r8, (%rax)
.L72:
	addq	$40, %rsp
	movq	%r8, %rax
	popq	%rbx
	popq	%rsi
	ret
	.p2align 4,,10
	.p2align 3
.L77:
	leaq	64(%rsp), %rdx
	leaq	memo(%rip), %rcx
	call	_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	movq	(%rax), %r8
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	movq	%r8, %rax
	ret
	.p2align 4,,10
	.p2align 3
.L80:
	call	_Z1fx
	movq	%rax, %rsi
	movq	64(%rsp), %rax
	movq	%rax, %rcx
	shrq	$63, %rcx
	addq	%rax, %rcx
	sarq	%rcx
	addq	$1, %rcx
	call	_Z1fx
	leaq	64(%rsp), %rdx
	leaq	memo(%rip), %rcx
	movq	%rax, %rbx
	call	_ZNSt8__detail9_Map_baseIxSt4pairIKxxESaIS3_ENS_10_Select1stESt8equal_toIxESt4hashIxENS_18_Mod_range_hashingENS_20_Default_ranged_hashENS_20_Prime_rehash_policyENS_17_Hashtable_traitsILb0ELb0ELb1EEELb1EEixERS2_
	leaq	(%rsi,%rbx), %r8
	movq	%r8, (%rax)
	addq	$40, %rsp
	movq	%r8, %rax
	popq	%rbx
	popq	%rsi
	ret
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$56, %rsp
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	40(%rsp), %rdx
	call	_ZNSi10_M_extractIxEERSiRT_
	movq	40(%rsp), %rcx
	call	_Z1fx
	movq	.refptr._ZSt4cout(%rip), %rcx
	movq	%rax, %rdx
	call	_ZNSo9_M_insertIxEERSoT_
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.p2align 4
	.def	_GLOBAL__sub_I_memo;	.scl	3;	.type	32;	.endef
_GLOBAL__sub_I_memo:
	subq	$40, %rsp
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	48+memo(%rip), %rax
	movq	$1, 8+memo(%rip)
	leaq	__tcf_1(%rip), %rcx
	movq	%rax, memo(%rip)
	movq	$0, 16+memo(%rip)
	movq	$0, 24+memo(%rip)
	movl	$0x3f800000, 32+memo(%rip)
	movq	$0, 40+memo(%rip)
	movq	$0, 48+memo(%rip)
	addq	$40, %rsp
	jmp	atexit
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_memo
	.globl	memo
	.bss
	.align 32
memo:
	.space 56
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 9.2.0"
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEyyy;	.scl	2;	.type	32;	.endef
	.def	_ZNSi10_M_extractIxEERSiRT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIxEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
