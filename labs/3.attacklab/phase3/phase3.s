
# https://www.redhat.com/en/blog/linkers-warnings-about-executable-stacks-and-segments
.section  .note.GNU-stack, "x", @progbits

.text
.global main
main:

    mov $0x556415f8, %rdi
    pushq $0x4019ed
    ret
