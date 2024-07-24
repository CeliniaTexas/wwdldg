declare i32 @getint()
declare float @getfloat()
declare i32 @getch()
declare i32 @getarray(i32*)
declare i32 @getfarray(float*)
declare void @putint(i32)
declare void @putfloat(float)
declare void @putch(i32)
declare void @putarray(i32, i32*)
declare void @putfarray(i32, float*)
declare void @_sysy_starttime(i32)
declare void @_sysy_stoptime(i32)
declare void @__aeabi_memcpy4(i32*, i32*, i32)
declare void @__aeabi_memclr4(i32*, i32)
declare void @__aeabi_memset4(i32*, i32, i32)
declare void @llvm.memset.p0.i32(i32*, i8, i32, i1)
define i32 @main() {
label_entry:
  %v0 = alloca i32
  %v1 = alloca i32
  store i32 3, i32* %v1
  %v2 = alloca i32
  store i32 5, i32* %v2
  %v3 = load i32, i32* %v1
  %v4 = load i32, i32* %v2
  %v5 = add i32 %v3, %v4
  %v6 = alloca i32
  store i32 %v5, i32* %v6
  %v7 = load i32, i32* %v6
  store i32 %v7, i32* %v0
  br label %label_ret
label_ret:                                                ; preds = %label_entry
  %v8 = load i32, i32* %v0
  ret i32 %v8
}

