#include <string>
#include <llvmtranslate/libllvmtranslate.hh>

namespace llvmtranslate
{
const char* runtime_string()
{
  return "\
; ModuleID = 'src/llvmtranslate/tiger-runtime.c'\n\
source_filename = \"src/llvmtranslate/tiger-runtime.c\"\n\
target datalayout = \"e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-f64:32:64-f80:32-n8:16:32-S128\"\n\
target triple = \"i686-unknown-linux-gnu\"\n\
\n\
%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i32, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i32, i32, [40 x i8] }\n\
%struct._IO_marker = type opaque\n\
%struct._IO_codecvt = type opaque\n\
%struct._IO_wide_data = type opaque\n\
\n\
@.str = private unnamed_addr constant [29 x i8] c\"chr: character out of range\\0A\\00\", align 1\n\
@stderr = external dso_local global %struct._IO_FILE*, align 4\n\
@consts = internal global [512 x i8] zeroinitializer, align 1\n\
@.str.1 = private unnamed_addr constant [36 x i8] c\"substring: arguments out of bounds\\0A\\00\", align 1\n\
@stdin = external dso_local global %struct._IO_FILE*, align 4\n\
@.str.2 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1\n\
@.str.3 = private unnamed_addr constant [3 x i8] c\"%s\\00\", align 1\n\
@.str.4 = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1\n\
@stdout = external dso_local global %struct._IO_FILE*, align 4\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32* @tc_init_array(i32 %0, i32 %1) #0 {\n\
  %3 = alloca i32, align 4\n\
  %4 = alloca i32, align 4\n\
  %5 = alloca i32*, align 4\n\
  %6 = alloca i32, align 4\n\
  store i32 %0, i32* %3, align 4\n\
  store i32 %1, i32* %4, align 4\n\
  %7 = load i32, i32* %3, align 4\n\
  %8 = mul i32 %7, 4\n\
  %9 = call noalias i8* @malloc(i32 %8) #5\n\
  %10 = bitcast i8* %9 to i32*\n\
  store i32* %10, i32** %5, align 4\n\
  store i32 0, i32* %6, align 4\n\
  br label %11\n\
\n\
11:                                               ; preds = %20, %2\n\
  %12 = load i32, i32* %6, align 4\n\
  %13 = load i32, i32* %3, align 4\n\
  %14 = icmp ult i32 %12, %13\n\
  br i1 %14, label %15, label %23\n\
\n\
15:                                               ; preds = %11\n\
  %16 = load i32, i32* %4, align 4\n\
  %17 = load i32*, i32** %5, align 4\n\
  %18 = load i32, i32* %6, align 4\n\
  %19 = getelementptr inbounds i32, i32* %17, i32 %18\n\
  store i32 %16, i32* %19, align 4\n\
  br label %20\n\
\n\
20:                                               ; preds = %15\n\
  %21 = load i32, i32* %6, align 4\n\
  %22 = add i32 %21, 1\n\
  store i32 %22, i32* %6, align 4\n\
  br label %11\n\
\n\
23:                                               ; preds = %11\n\
  %24 = load i32*, i32** %5, align 4\n\
  ret i32* %24\n\
}\n\
\n\
; Function Attrs: nounwind\n\
declare dso_local noalias i8* @malloc(i32) #1\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @tc_not(i32 %0) #0 {\n\
  %2 = alloca i32, align 4\n\
  store i32 %0, i32* %2, align 4\n\
  %3 = load i32, i32* %2, align 4\n\
  %4 = icmp ne i32 %3, 0\n\
  %5 = xor i1 %4, true\n\
  %6 = zext i1 %5 to i32\n\
  ret i32 %6\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local void @tc_exit(i32 %0) #0 {\n\
  %2 = alloca i32, align 4\n\
  store i32 %0, i32* %2, align 4\n\
  %3 = load i32, i32* %2, align 4\n\
  call void @exit(i32 %3) #6\n\
  unreachable\n\
}\n\
\n\
; Function Attrs: noreturn nounwind\n\
declare dso_local void @exit(i32) #2\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i8* @tc_chr(i32 %0) #0 {\n\
  %2 = alloca i32, align 4\n\
  store i32 %0, i32* %2, align 4\n\
  %3 = load i32, i32* %2, align 4\n\
  %4 = icmp sle i32 0, %3\n\
  br i1 %4, label %5, label %8\n\
\n\
5:                                                ; preds = %1\n\
  %6 = load i32, i32* %2, align 4\n\
  %7 = icmp sle i32 %6, 255\n\
  br i1 %7, label %11, label %8\n\
\n\
8:                                                ; preds = %5, %1\n\
  %9 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4\n\
  %10 = call i32 @fputs(i8* getelementptr inbounds ([29 x i8], [29 x i8]* @.str, i32 0, i32 0), %struct._IO_FILE* %9)\n\
  call void @exit(i32 120) #6\n\
  unreachable\n\
\n\
11:                                               ; preds = %5\n\
  %12 = load i32, i32* %2, align 4\n\
  %13 = mul nsw i32 %12, 2\n\
  %14 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %13\n\
  ret i8* %14\n\
}\n\
\n\
declare dso_local i32 @fputs(i8*, %struct._IO_FILE*) #3\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i8* @tc_concat(i8* %0, i8* %1) #0 {\n\
  %3 = alloca i8*, align 4\n\
  %4 = alloca i8*, align 4\n\
  %5 = alloca i8*, align 4\n\
  %6 = alloca i32, align 4\n\
  %7 = alloca i32, align 4\n\
  %8 = alloca i32, align 4\n\
  %9 = alloca i32, align 4\n\
  %10 = alloca i8*, align 4\n\
  store i8* %0, i8** %4, align 4\n\
  store i8* %1, i8** %5, align 4\n\
  %11 = load i8*, i8** %4, align 4\n\
  %12 = call i32 @strlen(i8* %11) #7\n\
  store i32 %12, i32* %6, align 4\n\
  %13 = load i8*, i8** %5, align 4\n\
  %14 = call i32 @strlen(i8* %13) #7\n\
  store i32 %14, i32* %7, align 4\n\
  %15 = load i32, i32* %6, align 4\n\
  %16 = icmp eq i32 %15, 0\n\
  br i1 %16, label %17, label %19\n\
\n\
17:                                               ; preds = %2\n\
  %18 = load i8*, i8** %5, align 4\n\
  store i8* %18, i8** %3, align 4\n\
  br label %69\n\
\n\
19:                                               ; preds = %2\n\
  %20 = load i32, i32* %7, align 4\n\
  %21 = icmp eq i32 %20, 0\n\
  br i1 %21, label %22, label %24\n\
\n\
22:                                               ; preds = %19\n\
  %23 = load i8*, i8** %4, align 4\n\
  store i8* %23, i8** %3, align 4\n\
  br label %69\n\
\n\
24:                                               ; preds = %19\n\
  store i32 0, i32* %8, align 4\n\
  %25 = load i32, i32* %6, align 4\n\
  %26 = load i32, i32* %7, align 4\n\
  %27 = add i32 %25, %26\n\
  store i32 %27, i32* %9, align 4\n\
  %28 = load i32, i32* %9, align 4\n\
  %29 = add nsw i32 %28, 1\n\
  %30 = call noalias i8* @malloc(i32 %29) #5\n\
  store i8* %30, i8** %10, align 4\n\
  store i32 0, i32* %8, align 4\n\
  br label %31\n\
\n\
31:                                               ; preds = %43, %24\n\
  %32 = load i32, i32* %8, align 4\n\
  %33 = load i32, i32* %6, align 4\n\
  %34 = icmp ult i32 %32, %33\n\
  br i1 %34, label %35, label %46\n\
\n\
35:                                               ; preds = %31\n\
  %36 = load i8*, i8** %4, align 4\n\
  %37 = load i32, i32* %8, align 4\n\
  %38 = getelementptr inbounds i8, i8* %36, i32 %37\n\
  %39 = load i8, i8* %38, align 1\n\
  %40 = load i8*, i8** %10, align 4\n\
  %41 = load i32, i32* %8, align 4\n\
  %42 = getelementptr inbounds i8, i8* %40, i32 %41\n\
  store i8 %39, i8* %42, align 1\n\
  br label %43\n\
\n\
43:                                               ; preds = %35\n\
  %44 = load i32, i32* %8, align 4\n\
  %45 = add nsw i32 %44, 1\n\
  store i32 %45, i32* %8, align 4\n\
  br label %31\n\
\n\
46:                                               ; preds = %31\n\
  store i32 0, i32* %8, align 4\n\
  br label %47\n\
\n\
47:                                               ; preds = %61, %46\n\
  %48 = load i32, i32* %8, align 4\n\
  %49 = load i32, i32* %7, align 4\n\
  %50 = icmp ult i32 %48, %49\n\
  br i1 %50, label %51, label %64\n\
\n\
51:                                               ; preds = %47\n\
  %52 = load i8*, i8** %5, align 4\n\
  %53 = load i32, i32* %8, align 4\n\
  %54 = getelementptr inbounds i8, i8* %52, i32 %53\n\
  %55 = load i8, i8* %54, align 1\n\
  %56 = load i8*, i8** %10, align 4\n\
  %57 = load i32, i32* %8, align 4\n\
  %58 = load i32, i32* %6, align 4\n\
  %59 = add i32 %57, %58\n\
  %60 = getelementptr inbounds i8, i8* %56, i32 %59\n\
  store i8 %55, i8* %60, align 1\n\
  br label %61\n\
\n\
61:                                               ; preds = %51\n\
  %62 = load i32, i32* %8, align 4\n\
  %63 = add nsw i32 %62, 1\n\
  store i32 %63, i32* %8, align 4\n\
  br label %47\n\
\n\
64:                                               ; preds = %47\n\
  %65 = load i8*, i8** %10, align 4\n\
  %66 = load i32, i32* %9, align 4\n\
  %67 = getelementptr inbounds i8, i8* %65, i32 %66\n\
  store i8 0, i8* %67, align 1\n\
  %68 = load i8*, i8** %10, align 4\n\
  store i8* %68, i8** %3, align 4\n\
  br label %69\n\
\n\
69:                                               ; preds = %64, %22, %17\n\
  %70 = load i8*, i8** %3, align 4\n\
  ret i8* %70\n\
}\n\
\n\
; Function Attrs: nounwind readonly\n\
declare dso_local i32 @strlen(i8*) #4\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @tc_ord(i8* %0) #0 {\n\
  %2 = alloca i32, align 4\n\
  %3 = alloca i8*, align 4\n\
  %4 = alloca i32, align 4\n\
  store i8* %0, i8** %3, align 4\n\
  %5 = load i8*, i8** %3, align 4\n\
  %6 = call i32 @strlen(i8* %5) #7\n\
  store i32 %6, i32* %4, align 4\n\
  %7 = load i32, i32* %4, align 4\n\
  %8 = icmp eq i32 %7, 0\n\
  br i1 %8, label %9, label %10\n\
\n\
9:                                                ; preds = %1\n\
  store i32 -1, i32* %2, align 4\n\
  br label %15\n\
\n\
10:                                               ; preds = %1\n\
  %11 = load i8*, i8** %3, align 4\n\
  %12 = getelementptr inbounds i8, i8* %11, i32 0\n\
  %13 = load i8, i8* %12, align 1\n\
  %14 = sext i8 %13 to i32\n\
  store i32 %14, i32* %2, align 4\n\
  br label %15\n\
\n\
15:                                               ; preds = %10, %9\n\
  %16 = load i32, i32* %2, align 4\n\
  ret i32 %16\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @tc_size(i8* %0) #0 {\n\
  %2 = alloca i8*, align 4\n\
  store i8* %0, i8** %2, align 4\n\
  %3 = load i8*, i8** %2, align 4\n\
  %4 = call i32 @strlen(i8* %3) #7\n\
  ret i32 %4\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i8* @tc_substring(i8* %0, i32 %1, i32 %2) #0 {\n\
  %4 = alloca i8*, align 4\n\
  %5 = alloca i8*, align 4\n\
  %6 = alloca i32, align 4\n\
  %7 = alloca i32, align 4\n\
  %8 = alloca i32, align 4\n\
  %9 = alloca i8*, align 4\n\
  %10 = alloca i32, align 4\n\
  store i8* %0, i8** %5, align 4\n\
  store i32 %1, i32* %6, align 4\n\
  store i32 %2, i32* %7, align 4\n\
  %11 = load i8*, i8** %5, align 4\n\
  %12 = call i32 @strlen(i8* %11) #7\n\
  store i32 %12, i32* %8, align 4\n\
  %13 = load i32, i32* %6, align 4\n\
  %14 = icmp sle i32 0, %13\n\
  br i1 %14, label %15, label %24\n\
\n\
15:                                               ; preds = %3\n\
  %16 = load i32, i32* %7, align 4\n\
  %17 = icmp sle i32 0, %16\n\
  br i1 %17, label %18, label %24\n\
\n\
18:                                               ; preds = %15\n\
  %19 = load i32, i32* %6, align 4\n\
  %20 = load i32, i32* %7, align 4\n\
  %21 = add nsw i32 %19, %20\n\
  %22 = load i32, i32* %8, align 4\n\
  %23 = icmp ule i32 %21, %22\n\
  br i1 %23, label %27, label %24\n\
\n\
24:                                               ; preds = %18, %15, %3\n\
  %25 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4\n\
  %26 = call i32 @fputs(i8* getelementptr inbounds ([36 x i8], [36 x i8]* @.str.1, i32 0, i32 0), %struct._IO_FILE* %25)\n\
  call void @exit(i32 120) #6\n\
  unreachable\n\
\n\
27:                                               ; preds = %18\n\
  %28 = load i32, i32* %7, align 4\n\
  %29 = icmp eq i32 %28, 1\n\
  br i1 %29, label %30, label %38\n\
\n\
30:                                               ; preds = %27\n\
  %31 = load i8*, i8** %5, align 4\n\
  %32 = load i32, i32* %6, align 4\n\
  %33 = getelementptr inbounds i8, i8* %31, i32 %32\n\
  %34 = load i8, i8* %33, align 1\n\
  %35 = sext i8 %34 to i32\n\
  %36 = mul nsw i32 %35, 2\n\
  %37 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %36\n\
  store i8* %37, i8** %4, align 4\n\
  br label %64\n\
\n\
38:                                               ; preds = %27\n\
  %39 = load i32, i32* %7, align 4\n\
  %40 = add nsw i32 %39, 1\n\
  %41 = call noalias i8* @malloc(i32 %40) #5\n\
  store i8* %41, i8** %9, align 4\n\
  store i32 0, i32* %10, align 4\n\
  br label %42\n\
\n\
42:                                               ; preds = %56, %38\n\
  %43 = load i32, i32* %10, align 4\n\
  %44 = load i32, i32* %7, align 4\n\
  %45 = icmp slt i32 %43, %44\n\
  br i1 %45, label %46, label %59\n\
\n\
46:                                               ; preds = %42\n\
  %47 = load i8*, i8** %5, align 4\n\
  %48 = load i32, i32* %6, align 4\n\
  %49 = load i32, i32* %10, align 4\n\
  %50 = add nsw i32 %48, %49\n\
  %51 = getelementptr inbounds i8, i8* %47, i32 %50\n\
  %52 = load i8, i8* %51, align 1\n\
  %53 = load i8*, i8** %9, align 4\n\
  %54 = load i32, i32* %10, align 4\n\
  %55 = getelementptr inbounds i8, i8* %53, i32 %54\n\
  store i8 %52, i8* %55, align 1\n\
  br label %56\n\
\n\
56:                                               ; preds = %46\n\
  %57 = load i32, i32* %10, align 4\n\
  %58 = add nsw i32 %57, 1\n\
  store i32 %58, i32* %10, align 4\n\
  br label %42\n\
\n\
59:                                               ; preds = %42\n\
  %60 = load i8*, i8** %9, align 4\n\
  %61 = load i32, i32* %7, align 4\n\
  %62 = getelementptr inbounds i8, i8* %60, i32 %61\n\
  store i8 0, i8* %62, align 1\n\
  %63 = load i8*, i8** %9, align 4\n\
  store i8* %63, i8** %4, align 4\n\
  br label %64\n\
\n\
64:                                               ; preds = %59, %30\n\
  %65 = load i8*, i8** %4, align 4\n\
  ret i8* %65\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @tc_strcmp(i8* %0, i8* %1) #0 {\n\
  %3 = alloca i8*, align 4\n\
  %4 = alloca i8*, align 4\n\
  store i8* %0, i8** %3, align 4\n\
  store i8* %1, i8** %4, align 4\n\
  %5 = load i8*, i8** %3, align 4\n\
  %6 = load i8*, i8** %4, align 4\n\
  %7 = call i32 @strcmp(i8* %5, i8* %6) #7\n\
  ret i32 %7\n\
}\n\
\n\
; Function Attrs: nounwind readonly\n\
declare dso_local i32 @strcmp(i8*, i8*) #4\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @tc_streq(i8* %0, i8* %1) #0 {\n\
  %3 = alloca i8*, align 4\n\
  %4 = alloca i8*, align 4\n\
  store i8* %0, i8** %3, align 4\n\
  store i8* %1, i8** %4, align 4\n\
  %5 = load i8*, i8** %3, align 4\n\
  %6 = load i8*, i8** %4, align 4\n\
  %7 = call i32 @strcmp(i8* %5, i8* %6) #7\n\
  %8 = icmp eq i32 %7, 0\n\
  %9 = zext i1 %8 to i32\n\
  ret i32 %9\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i8* @tc_getchar() #0 {\n\
  %1 = alloca i8*, align 4\n\
  %2 = alloca i32, align 4\n\
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @stdin, align 4\n\
  %4 = call i32 @getc(%struct._IO_FILE* %3)\n\
  store i32 %4, i32* %2, align 4\n\
  %5 = load i32, i32* %2, align 4\n\
  %6 = icmp eq i32 %5, -1\n\
  br i1 %6, label %7, label %8\n\
\n\
7:                                                ; preds = %0\n\
  store i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.str.2, i32 0, i32 0), i8** %1, align 4\n\
  br label %12\n\
\n\
8:                                                ; preds = %0\n\
  %9 = load i32, i32* %2, align 4\n\
  %10 = mul nsw i32 %9, 2\n\
  %11 = getelementptr inbounds i8, i8* getelementptr inbounds ([512 x i8], [512 x i8]* @consts, i32 0, i32 0), i32 %10\n\
  store i8* %11, i8** %1, align 4\n\
  br label %12\n\
\n\
12:                                               ; preds = %8, %7\n\
  %13 = load i8*, i8** %1, align 4\n\
  ret i8* %13\n\
}\n\
\n\
declare dso_local i32 @getc(%struct._IO_FILE*) #3\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local void @tc_print(i8* %0) #0 {\n\
  %2 = alloca i8*, align 4\n\
  store i8* %0, i8** %2, align 4\n\
  %3 = load i8*, i8** %2, align 4\n\
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8* %3)\n\
  ret void\n\
}\n\
\n\
declare dso_local i32 @printf(i8*, ...) #3\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local void @tc_print_err(i8* %0) #0 {\n\
  %2 = alloca i8*, align 4\n\
  store i8* %0, i8** %2, align 4\n\
  %3 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 4\n\
  %4 = load i8*, i8** %2, align 4\n\
  %5 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.3, i32 0, i32 0), i8* %4)\n\
  ret void\n\
}\n\
\n\
declare dso_local i32 @fprintf(%struct._IO_FILE*, i8*, ...) #3\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local void @tc_print_int(i32 %0) #0 {\n\
  %2 = alloca i32, align 4\n\
  store i32 %0, i32* %2, align 4\n\
  %3 = load i32, i32* %2, align 4\n\
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.4, i32 0, i32 0), i32 %3)\n\
  ret void\n\
}\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local void @tc_flush() #0 {\n\
  %1 = load %struct._IO_FILE*, %struct._IO_FILE** @stdout, align 4\n\
  %2 = call i32 @fflush(%struct._IO_FILE* %1)\n\
  ret void\n\
}\n\
\n\
declare dso_local i32 @fflush(%struct._IO_FILE*) #3\n\
\n\
; Function Attrs: noinline nounwind optnone\n\
define dso_local i32 @main() #0 {\n\
  %1 = alloca i32, align 4\n\
  %2 = alloca i32, align 4\n\
  store i32 0, i32* %1, align 4\n\
  store i32 0, i32* %2, align 4\n\
  br label %3\n\
\n\
3:                                                ; preds = %15, %0\n\
  %4 = load i32, i32* %2, align 4\n\
  %5 = icmp slt i32 %4, 512\n\
  br i1 %5, label %6, label %18\n\
\n\
6:                                                ; preds = %3\n\
  %7 = load i32, i32* %2, align 4\n\
  %8 = sdiv i32 %7, 2\n\
  %9 = trunc i32 %8 to i8\n\
  %10 = load i32, i32* %2, align 4\n\
  %11 = getelementptr inbounds [512 x i8], [512 x i8]* @consts, i32 0, i32 %10\n\
  store i8 %9, i8* %11, align 1\n\
  %12 = load i32, i32* %2, align 4\n\
  %13 = add nsw i32 %12, 1\n\
  %14 = getelementptr inbounds [512 x i8], [512 x i8]* @consts, i32 0, i32 %13\n\
  store i8 0, i8* %14, align 1\n\
  br label %15\n\
\n\
15:                                               ; preds = %6\n\
  %16 = load i32, i32* %2, align 4\n\
  %17 = add nsw i32 %16, 2\n\
  store i32 %17, i32* %2, align 4\n\
  br label %3\n\
\n\
18:                                               ; preds = %3\n\
  call void @tc_main(i32 0)\n\
  ret i32 0\n\
}\n\
\n\
declare dso_local void @tc_main(i32) #3\n\
\n\
attributes #0 = { noinline nounwind optnone \"correctly-rounded-divide-sqrt-fp-math\"=\"false\" \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"all\" \"less-precise-fpmad\"=\"false\" \"min-legal-vector-width\"=\"0\" \"no-infs-fp-math\"=\"false\" \"no-jump-tables\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"pentium4\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n\
attributes #1 = { nounwind \"correctly-rounded-divide-sqrt-fp-math\"=\"false\" \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"all\" \"less-precise-fpmad\"=\"false\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"pentium4\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n\
attributes #2 = { noreturn nounwind \"correctly-rounded-divide-sqrt-fp-math\"=\"false\" \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"all\" \"less-precise-fpmad\"=\"false\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"pentium4\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n\
attributes #3 = { \"correctly-rounded-divide-sqrt-fp-math\"=\"false\" \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"all\" \"less-precise-fpmad\"=\"false\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"pentium4\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n\
attributes #4 = { nounwind readonly \"correctly-rounded-divide-sqrt-fp-math\"=\"false\" \"disable-tail-calls\"=\"false\" \"frame-pointer\"=\"all\" \"less-precise-fpmad\"=\"false\" \"no-infs-fp-math\"=\"false\" \"no-nans-fp-math\"=\"false\" \"no-signed-zeros-fp-math\"=\"false\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"pentium4\" \"target-features\"=\"+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"unsafe-fp-math\"=\"false\" \"use-soft-float\"=\"false\" }\n\
attributes #5 = { nounwind }\n\
attributes #6 = { noreturn nounwind }\n\
attributes #7 = { nounwind readonly }\n\
\n\
!llvm.module.flags = !{!0, !1}\n\
!llvm.ident = !{!2}\n\
\n\
!0 = !{i32 1, !\"NumRegisterParameters\", i32 0}\n\
!1 = !{i32 1, !\"wchar_size\", i32 4}\n\
!2 = !{!\"clang version 11.1.0\"}\n\
";
}
} // namespace llvmtranslate
