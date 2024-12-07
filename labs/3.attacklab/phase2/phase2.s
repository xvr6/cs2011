
# https://www.redhat.com/en/blog/linkers-warnings-about-executable-stacks-and-segments
.section  .note.GNU-stack, "x", @progbits

.text
.global main
main:

    mov $0x7093ff41, %rdi
    pushq $0x4018dc
    ret
