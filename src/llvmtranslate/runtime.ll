; ModuleID = 'src/llvmtranslate/tiger-runtime.c'
source_filename = "src/llvmtranslate/tiger-runtime.c"
target datalayout = "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i686-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i32, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i32, i32, [40 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque

@.str = private unnamed_addr constant [29 x i8] c"chr: character out of range\0A\00", align 1
@stderr = external dso_local global %struct._IO_FILE*, align 4
@consts = internal global [512 x i8] zeroinitializer, align 1
@.str.1 = private unnamed_addr constant [36 x i8] c"substring: arguments out of bounds\0A\00", align 1
@stdin = external dso_local global %struct._IO_FILE*, align 4
@.str.2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@.str.3 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str.4 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@stdout = external dso_local global %struct._IO_FILE*, align 4

; Function Attrs: noinline nounwind optnone
define dso_local i32* @tc_init_array(i32 %0, i32 %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32*, align 4
  %6 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %7 = load i32, i32* %3, align 4
  %8 = mul i32 %7, 4
  %9 = call noalias i8* @malloc(i32 %8) #5
  %10 = bitcast i8* %9 to i32*
  store i32* %10, i32** %5, align 4
  store i32 0, i32* %6, align 4
  br label %11

11:                                               ; preds = %20, %2
  %12 = load i32, i32* %6, align 4
  %13 = load i32, i32* %3, align 4
  %14 = icmp ult i32 %12, %13
  br i1 %14, label %15, label %23

15:                                               ; preds = %11
  %16 = load i32, i32* %4, align 4
  %17 = load i32*, i32** %5, align 4
  %18 = load i32, i32* %6, align 4
  %19 = getelementptr inbounds i32, i32* %17, i32 %18
  store i32 %16, i32* %19, align 4
  br label %20

20:                                               ; preds = %15
  %21 = load i32, i32* %6, align 4
  %22 = add i32 %21, 1
  store i32 %22, i32* %6, align 4
  br label %11

23:                                               ; preds = %11
  %24 = load i32*, i32** %5, align 4
  ret i32* %24
}

; Function Attrs: nounwind
declare dso_local noalias i8* @malloc(i32) #1

; Function Attrs: noinline nounwind optnone
define dso_local i32 @tc_not(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp ne i32 %3, 0
  %5 = xor i1 %4, true
  %6 = zext i1 %5 to i32
  ret i32 %6
}

; Function Attrs: noinline nounwind optnone
define dso_local void @tc_exit(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  call void @exit(i32 %3) #6
  unreachable
}

; Function Attrs: noreturn nounwind
declare dso_local void @exit(i32) #2

; Function Attrs: noinline nounwind optnone
define dso_local i8* @tc_chr(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp sle i32 0, %3
  br i1 %4, label %5, label %8

5:                                                ; preds = %1
  %6 = load i32, i32* %2, align 4
  %7 = icmp sle i32 %6, 255
  br i1 %7, label %11, label %8

8:                                                ; preds = %5, %1
  %9 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4
  %10 = call i32 @fputs(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str, i32 0, i32 0), %struct._IO_FILE* %9)
  call void @exit(i32 120) #6
  unreachable

11:                                               ; preds = %5
  %12 = load i32, i32* %2, align 4
  %13 = mul nsw i32 %12, 2
  %14 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %13
  ret i8* %14
}

declare dso_local i32 @fputs(i8*, %struct._IO_FILE*) #3

; Function Attrs: noinline nounwind optnone
define dso_local i8* @tc_concat(i8* %0, i8* %1) #0 {
  %3 = alloca i8*, align 4
  %4 = alloca i8*, align 4
  %5 = alloca i8*, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i8*, align 4
  store i8* %0, i8** %4, align 4
  store i8* %1, i8** %5, align 4
  %11 = load i8*, i8** %4, align 4
  %12 = call i32 @strlen(i8* %11) #7
  store i32 %12, i32* %6, align 4
  %13 = load i8*, i8** %5, align 4
  %14 = call i32 @strlen(i8* %13) #7
  store i32 %14, i32* %7, align 4
  %15 = load i32, i32* %6, align 4
  %16 = icmp eq i32 %15, 0
  br i1 %16, label %17, label %19

17:                                               ; preds = %2
  %18 = load i8*, i8** %5, align 4
  store i8* %18, i8** %3, align 4
  br label %69

19:                                               ; preds = %2
  %20 = load i32, i32* %7, align 4
  %21 = icmp eq i32 %20, 0
  br i1 %21, label %22, label %24

22:                                               ; preds = %19
  %23 = load i8*, i8** %4, align 4
  store i8* %23, i8** %3, align 4
  br label %69

24:                                               ; preds = %19
  store i32 0, i32* %8, align 4
  %25 = load i32, i32* %6, align 4
  %26 = load i32, i32* %7, align 4
  %27 = add i32 %25, %26
  store i32 %27, i32* %9, align 4
  %28 = load i32, i32* %9, align 4
  %29 = add nsw i32 %28, 1
  %30 = call noalias i8* @malloc(i32 %29) #5
  store i8* %30, i8** %10, align 4
  store i32 0, i32* %8, align 4
  br label %31

31:                                               ; preds = %43, %24
  %32 = load i32, i32* %8, align 4
  %33 = load i32, i32* %6, align 4
  %34 = icmp ult i32 %32, %33
  br i1 %34, label %35, label %46

35:                                               ; preds = %31
  %36 = load i8*, i8** %4, align 4
  %37 = load i32, i32* %8, align 4
  %38 = getelementptr inbounds i8, i8* %36, i32 %37
  %39 = load i8, i8* %38, align 1
  %40 = load i8*, i8** %10, align 4
  %41 = load i32, i32* %8, align 4
  %42 = getelementptr inbounds i8, i8* %40, i32 %41
  store i8 %39, i8* %42, align 1
  br label %43

43:                                               ; preds = %35
  %44 = load i32, i32* %8, align 4
  %45 = add nsw i32 %44, 1
  store i32 %45, i32* %8, align 4
  br label %31

46:                                               ; preds = %31
  store i32 0, i32* %8, align 4
  br label %47

47:                                               ; preds = %61, %46
  %48 = load i32, i32* %8, align 4
  %49 = load i32, i32* %7, align 4
  %50 = icmp ult i32 %48, %49
  br i1 %50, label %51, label %64

51:                                               ; preds = %47
  %52 = load i8*, i8** %5, align 4
  %53 = load i32, i32* %8, align 4
  %54 = getelementptr inbounds i8, i8* %52, i32 %53
  %55 = load i8, i8* %54, align 1
  %56 = load i8*, i8** %10, align 4
  %57 = load i32, i32* %8, align 4
  %58 = load i32, i32* %6, align 4
  %59 = add i32 %57, %58
  %60 = getelementptr inbounds i8, i8* %56, i32 %59
  store i8 %55, i8* %60, align 1
  br label %61

61:                                               ; preds = %51
  %62 = load i32, i32* %8, align 4
  %63 = add nsw i32 %62, 1
  store i32 %63, i32* %8, align 4
  br label %47

64:                                               ; preds = %47
  %65 = load i8*, i8** %10, align 4
  %66 = load i32, i32* %9, align 4
  %67 = getelementptr inbounds i8, i8* %65, i32 %66
  store i8 0, i8* %67, align 1
  %68 = load i8*, i8** %10, align 4
  store i8* %68, i8** %3, align 4
  br label %69

69:                                               ; preds = %64, %22, %17
  %70 = load i8*, i8** %3, align 4
  ret i8* %70
}

; Function Attrs: nounwind readonly
declare dso_local i32 @strlen(i8*) #4

; Function Attrs: noinline nounwind optnone
define dso_local i32 @tc_ord(i8* %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i8*, align 4
  %4 = alloca i32, align 4
  store i8* %0, i8** %3, align 4
  %5 = load i8*, i8** %3, align 4
  %6 = call i32 @strlen(i8* %5) #7
  store i32 %6, i32* %4, align 4
  %7 = load i32, i32* %4, align 4
  %8 = icmp eq i32 %7, 0
  br i1 %8, label %9, label %10

9:                                                ; preds = %1
  store i32 -1, i32* %2, align 4
  br label %15

10:                                               ; preds = %1
  %11 = load i8*, i8** %3, align 4
  %12 = getelementptr inbounds i8, i8* %11, i32 0
  %13 = load i8, i8* %12, align 1
  %14 = sext i8 %13 to i32
  store i32 %14, i32* %2, align 4
  br label %15

15:                                               ; preds = %10, %9
  %16 = load i32, i32* %2, align 4
  ret i32 %16
}

; Function Attrs: noinline nounwind optnone
define dso_local i32 @tc_size(i8* %0) #0 {
  %2 = alloca i8*, align 4
  store i8* %0, i8** %2, align 4
  %3 = load i8*, i8** %2, align 4
  %4 = call i32 @strlen(i8* %3) #7
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone
define dso_local i8* @tc_substring(i8* %0, i32 %1, i32 %2) #0 {
  %4 = alloca i8*, align 4
  %5 = alloca i8*, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i8*, align 4
  %10 = alloca i32, align 4
  store i8* %0, i8** %5, align 4
  store i32 %1, i32* %6, align 4
  store i32 %2, i32* %7, align 4
  %11 = load i8*, i8** %5, align 4
  %12 = call i32 @strlen(i8* %11) #7
  store i32 %12, i32* %8, align 4
  %13 = load i32, i32* %6, align 4
  %14 = icmp sle i32 0, %13
  br i1 %14, label %15, label %24

15:                                               ; preds = %3
  %16 = load i32, i32* %7, align 4
  %17 = icmp sle i32 0, %16
  br i1 %17, label %18, label %24

18:                                               ; preds = %15
  %19 = load i32, i32* %6, align 4
  %20 = load i32, i32* %7, align 4
  %21 = add nsw i32 %19, %20
  %22 = load i32, i32* %8, align 4
  %23 = icmp ule i32 %21, %22
  br i1 %23, label %27, label %24

24:                                               ; preds = %18, %15, %3
  %25 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4
  %26 = call i32 @fputs(i8* getelementptr inbounds ([36 x i8], [36 x i8]* @.str.1, i32 0, i32 0), %struct._IO_FILE* %25)
  call void @exit(i32 120) #6
  unreachable

27:                                               ; preds = %18
  %28 = load i32, i32* %7, align 4
  %29 = icmp eq i32 %28, 1
  br i1 %29, label %30, label %38

30:                                               ; preds = %27
  %31 = load i8*, i8** %5, align 4
  %32 = load i32, i32* %6, align 4
  %33 = getelementptr inbounds i8, i8* %31, i32 %32
  %34 = load i8, i8* %33, align 1
  %35 = sext i8 %34 to i32
  %36 = mul nsw i32 %35, 2
  %37 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %36
  store i8* %37, i8** %4, align 4
  br label %64

38:                                               ; preds = %27
  %39 = load i32, i32* %7, align 4
  %40 = add nsw i32 %39, 1
  %41 = call noalias i8* @malloc(i32 %40) #5
  store i8* %41, i8** %9, align 4
  store i32 0, i32* %10, align 4
  br label %42

42:                                               ; preds = %56, %38
  %43 = load i32, i32* %10, align 4
  %44 = load i32, i32* %7, align 4
  %45 = icmp slt i32 %43, %44
  br i1 %45, label %46, label %59

46:                                               ; preds = %42
  %47 = load i8*, i8** %5, align 4
  %48 = load i32, i32* %6, align 4
  %49 = load i32, i32* %10, align 4
  %50 = add nsw i32 %48, %49
  %51 = getelementptr inbounds i8, i8* %47, i32 %50
  %52 = load i8, i8* %51, align 1
  %53 = load i8*, i8** %9, align 4
  %54 = load i32, i32* %10, align 4
  %55 = getelementptr inbounds i8, i8* %53, i32 %54
  store i8 %52, i8* %55, align 1
  br label %56

56:                                               ; preds = %46
  %57 = load i32, i32* %10, align 4
  %58 = add nsw i32 %57, 1
  store i32 %58, i32* %10, align 4
  br label %42

59:                                               ; preds = %42
  %60 = load i8*, i8** %9, align 4
  %61 = load i32, i32* %7, align 4
  %62 = getelementptr inbounds i8, i8* %60, i32 %61
  store i8 0, i8* %62, align 1
  %63 = load i8*, i8** %9, align 4
  store i8* %63, i8** %4, align 4
  br label %64

64:                                               ; preds = %59, %30
  %65 = load i8*, i8** %4, align 4
  ret i8* %65
}

; Function Attrs: noinline nounwind optnone
define dso_local i32 @tc_strcmp(i8* %0, i8* %1) #0 {
  %3 = alloca i8*, align 4
  %4 = alloca i8*, align 4
  store i8* %0, i8** %3, align 4
  store i8* %1, i8** %4, align 4
  %5 = load i8*, i8** %3, align 4
  %6 = load i8*, i8** %4, align 4
  %7 = call i32 @strcmp(i8* %5, i8* %6) #7
  ret i32 %7
}

; Function Attrs: nounwind readonly
declare dso_local i32 @strcmp(i8*, i8*) #4

; Function Attrs: noinline nounwind optnone
define dso_local i32 @tc_streq(i8* %0, i8* %1) #0 {
  %3 = alloca i8*, align 4
  %4 = alloca i8*, align 4
  store i8* %0, i8** %3, align 4
  store i8* %1, i8** %4, align 4
  %5 = load i8*, i8** %3, align 4
  %6 = load i8*, i8** %4, align 4
  %7 = call i32 @strcmp(i8* %5, i8* %6) #7
  %8 = icmp eq i32 %7, 0
  %9 = zext i1 %8 to i32
  ret i32 %9
}

; Function Attrs: noinline nounwind optnone
define dso_local i8* @tc_getchar() #0 {
  %1 = alloca i8*, align 4
  %2 = alloca i32, align 4
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @stdin, align 4
  %4 = call i32 @getc(%struct._IO_FILE* %3)
  store i32 %4, i32* %2, align 4
  %5 = load i32, i32* %2, align 4
  %6 = icmp eq i32 %5, -1
  br i1 %6, label %7, label %8

7:                                                ; preds = %0
  store i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.str.2, i32 0, i32 0), i8** %1, align 4
  br label %12

8:                                                ; preds = %0
  %9 = load i32, i32* %2, align 4
  %10 = mul nsw i32 %9, 2
  %11 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %10
  store i8* %11, i8** %1, align 4
  br label %12

12:                                               ; preds = %8, %7
  %13 = load i8*, i8** %1, align 4
  ret i8* %13
}

declare dso_local i32 @getc(%struct._IO_FILE*) #3

; Function Attrs: noinline nounwind optnone
define dso_local void @tc_print(i8* %0) #0 {
  %2 = alloca i8*, align 4
  store i8* %0, i8** %2, align 4
  %3 = load i8*, i8** %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8* %3)
  ret void
}

declare dso_local i32 @printf(i8*, ...) #3

; Function Attrs: noinline nounwind optnone
define dso_local void @tc_print_err(i8* %0) #0 {
  %2 = alloca i8*, align 4
  store i8* %0, i8** %2, align 4
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4
  %4 = load i8*, i8** %2, align 4
  %5 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8* %4)
  ret void
}

declare dso_local i32 @fprintf(%struct._IO_FILE*, i8*, ...) #3

; Function Attrs: noinline nounwind optnone
define dso_local void @tc_print_int(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0), i32 %3)
  ret void
}

; Function Attrs: noinline nounwind optnone
define dso_local void @tc_flush() #0 {
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 4
  %2 = call i32 @fflush(%struct._IO_FILE* %1)
  ret void
}

declare dso_local i32 @fflush(%struct._IO_FILE*) #3

; Function Attrs: noinline nounwind optnone
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 0, i32* %2, align 4
  br label %3

3:                                                ; preds = %15, %0
  %4 = load i32, i32* %2, align 4
  %5 = icmp slt i32 %4, 512
  br i1 %5, label %6, label %18

6:                                                ; preds = %3
  %7 = load i32, i32* %2, align 4
  %8 = sdiv i32 %7, 2
  %9 = trunc i32 %8 to i8
  %10 = load i32, i32* %2, align 4
  %11 = getelementptr inbounds [512 x i8], [512 x i8]* @consts, i32 0, i32 %10
  store i8 %9, i8* %11, align 1
  %12 = load i32, i32* %2, align 4
  %13 = add nsw i32 %12, 1
  %14 = getelementptr inbounds [512 x i8], [512 x i8]* @consts, i32 0, i32 %13
  store i8 0, i8* %14, align 1
  br label %15

15:                                               ; preds = %6
  %16 = load i32, i32* %2, align 4
  %17 = add nsw i32 %16, 2
  store i32 %17, i32* %2, align 4
  br label %3

18:                                               ; preds = %3
  call void @tc_main(i32 0)
  ret i32 0
}

declare dso_local void @tc_main(i32) #3

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readonly "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="pentium4" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind }
attributes #6 = { noreturn nounwind }
attributes #7 = { nounwind readonly }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"NumRegisterParameters", i32 0}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{!"clang version 11.1.0"}
