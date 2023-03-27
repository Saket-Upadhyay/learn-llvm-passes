; ModuleID = 'input_for_mba.ll'
source_filename = "input_for_mba.c"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx13.0.0"

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone ssp uwtable willreturn
define signext i8 @foo(i8 signext %0, i8 signext %1, i8 signext %2, i8 signext %3) local_unnamed_addr #0 {
  %5 = xor i8 %1, %0
  %6 = and i8 %1, %0
  %7 = mul i8 2, %6
  %8 = add i8 %5, %7
  %9 = mul i8 39, %8
  %10 = add i8 23, %9
  %11 = mul i8 -105, %10
  %12 = add i8 111, %11
  %13 = xor i8 %12, %2
  %14 = and i8 %12, %2
  %15 = mul i8 2, %14
  %16 = add i8 %13, %15
  %17 = mul i8 39, %16
  %18 = add i8 23, %17
  %19 = mul i8 -105, %18
  %20 = add i8 111, %19
  %21 = xor i8 %20, %3
  %22 = and i8 %20, %3
  %23 = mul i8 2, %22
  %24 = add i8 %21, %23
  %25 = mul i8 39, %24
  %26 = add i8 23, %25
  %27 = mul i8 -105, %26
  %28 = add i8 111, %27
  ret i8 %28
}

; Function Attrs: mustprogress nofree nounwind readonly ssp uwtable willreturn
define i32 @main(i32 %0, i8** nocapture readonly %1) local_unnamed_addr #1 {
  %3 = getelementptr inbounds i8*, i8** %1, i64 1
  %4 = load i8*, i8** %3, align 8, !tbaa !10
  %5 = call i32 @atoi(i8* %4)
  %6 = getelementptr inbounds i8*, i8** %1, i64 2
  %7 = load i8*, i8** %6, align 8, !tbaa !10
  %8 = call i32 @atoi(i8* %7)
  %9 = getelementptr inbounds i8*, i8** %1, i64 3
  %10 = load i8*, i8** %9, align 8, !tbaa !10
  %11 = call i32 @atoi(i8* %10)
  %12 = getelementptr inbounds i8*, i8** %1, i64 4
  %13 = load i8*, i8** %12, align 8, !tbaa !10
  %14 = call i32 @atoi(i8* %13)
  %15 = trunc i32 %5 to i8
  %16 = trunc i32 %8 to i8
  %17 = trunc i32 %11 to i8
  %18 = trunc i32 %14 to i8
  %19 = call signext i8 @foo(i8 signext %15, i8 signext %16, i8 signext %17, i8 signext %18)
  %20 = sext i8 %19 to i32
  ret i32 %20
}

; Function Attrs: mustprogress nofree nounwind readonly willreturn
declare i32 @atoi(i8* nocapture) local_unnamed_addr #2

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone ssp uwtable willreturn "frame-pointer"="non-leaf" "min-legal-vector-width"="0" "no-trapping-math"="true" "probe-stack"="__chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+crc,+crypto,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+lse,+neon,+ras,+rcpc,+rdm,+sha2,+sha3,+sm4,+v8.5a,+zcm,+zcz" }
attributes #1 = { mustprogress nofree nounwind readonly ssp uwtable willreturn "frame-pointer"="non-leaf" "min-legal-vector-width"="0" "no-trapping-math"="true" "probe-stack"="__chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+crc,+crypto,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+lse,+neon,+ras,+rcpc,+rdm,+sha2,+sha3,+sm4,+v8.5a,+zcm,+zcz" }
attributes #2 = { mustprogress nofree nounwind readonly willreturn "frame-pointer"="non-leaf" "no-trapping-math"="true" "probe-stack"="__chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+crc,+crypto,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+lse,+neon,+ras,+rcpc,+rdm,+sha2,+sha3,+sm4,+v8.5a,+zcm,+zcz" }

!llvm.module.flags = !{!0, !1, !2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 13, i32 1]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 1, !"branch-target-enforcement", i32 0}
!3 = !{i32 1, !"sign-return-address", i32 0}
!4 = !{i32 1, !"sign-return-address-all", i32 0}
!5 = !{i32 1, !"sign-return-address-with-bkey", i32 0}
!6 = !{i32 7, !"PIC Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 1}
!9 = !{!"Apple clang version 14.0.0 (clang-1400.0.29.202)"}
!10 = !{!11, !11, i64 0}
!11 = !{!"any pointer", !12, i64 0}
!12 = !{!"omnipotent char", !13, i64 0}
!13 = !{!"Simple C/C++ TBAA"}
