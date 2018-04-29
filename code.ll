; ModuleID = 'code.bc'
source_filename = "col728 lab2"

@0 = private constant [10 x i8] c"%d %d %d\0A\00", align 1

declare i32 @printf(i8*, ...)

define i32 @test_cse(i32 %x, i32 %y, i32 %w) {
entry:
  %multmp = mul i32 %y, %x
  %eqtmp = icmp eq i32 %w, 0
  %. = select i1 %eqtmp, i32 1, i32 0
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @0, i64 0, i64 0), i32 %multmp, i32 %multmp, i32 %.)
  ret i32 0
}

define i32 @main() {
entry:
  %0 = call i32 @test_cse(i32 2, i32 3, i32 1)
  ret i32 0
}
