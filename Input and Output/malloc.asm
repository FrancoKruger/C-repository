section .data
    ; Define constants
    NULL_PTR dd 0

section .bss
    memory_pool resb 4096  ; Define a memory pool of 4KB

section .text

; Custom malloc implementation
malloc:
    ; Input: eax = size of memory to allocate
    ; Output: eax = pointer to allocated memory (or NULL if allocation failed)

    ; Function prologue:
    push ebx
    push ecx
    push edx

    ; Load the size of memory to allocate into ebx
    mov ebx, eax

    ; Check for valid allocation size
    cmp ebx, 0
    jle .malloc_fail  ; Return NULL if size is zero or negative

    ; Find a free block in the memory pool (naive first-fit approach)
    mov esi, memory_pool  ; Start of the memory pool
.find_free_block:
    lodsd  ; Load a 32-bit value from esi into eax (block size)
    cmp eax, 0
    je .malloc_allocate  ; If block size is zero, allocate memory here
    add esi, eax  ; Move to the next block
    test esi, esi
    jnz .find_free_block

.malloc_fail:
    ; Failed to allocate memory
    mov eax, NULL_PTR
    jmp .malloc_end

.malloc_allocate:
    ; Allocate memory at esi
    mov ecx, ebx
    mov edx, esi
    add edx, ebx
    stosd  ; Store the allocated block size in the header
    mov eax, edx
    jmp .malloc_end

.malloc_end:
    ; Function epilogue
    pop edx
    pop ecx
    pop ebx
    ret

; void enqueue(QueueNode **queue, void *elem)
global enqueue
enqueue:
    push ebp
    mov ebp, esp

    ; Function prologue

    ; Parameters:
    ; [ebp+8]  - queue (QueueNode **)
    ; [ebp+12] - elem (void *)

    ; Create a new QueueNode
    push dword [ebp+12]       ; Push the address of elem onto the stack
    push dword [ebp+8]        ; Push the address of queue onto the stack
    call createQueueNode     ; Call createQueueNode(queue, elem)
    add esp, 8               ; Clean up the stack

    ; If *queue is NULL, set *queue to point to the new node
    mov eax, [ebp+8]          ; Load the address of queue
    cmp dword [eax], NULL_PTR ; Compare *queue to NULL
    jnz .notEmpty            ; Jump if it's not empty

    ; Set *queue to point to the new node
    mov edx, [ebp+8]          ; Load the address of queue
    mov ebx, [ebp+12]         ; Load the address of elem
    mov [edx], ebx            ; Set *queue to point to the new node

.notEmpty:
    ; Function epilogue:
    leave
    ret

; Helper function to create a new QueueNode
createQueueNode:
    push ebp
    mov ebp, esp

    ; Parameters:
    ; [ebp+8]  - queue (QueueNode **)
    ; [ebp+12] - elem (void *)

    ; Allocate memory for the new QueueNode
    push 8                   ; Size of a QueueNode structure
    call malloc             ; Call the memory allocation function (e.g., malloc)
    add esp, 4               ; Clean up the stack

    ; Initialize the new QueueNode
    mov ebx, [ebp+8]          ; Load queue
    mov edi, [ebp+12]         ; Load elem
    mov [eax], edi            ; Set elem (elem->elem) to the address of elem
    mov [eax+4], NULL_PTR     ; Set next (elem->next) to NULL

    ; Return the address of the new QueueNode in eax
    mov eax, [ebp+8]

    ; Function epilogue:
    leave
    ret

; void *dequeue(QueueNode **queue)
global dequeue
dequeue:
    push ebp
    mov ebp, esp

    ; Function prologue

    ; Parameter:
    ; [ebp+8] - queue (QueueNode **)

    ; If the queue is empty (queue is NULL or *queue is NULL), return NULL
    mov eax, [ebp+8]          ; Load the address of queue
    cmp dword [eax], NULL_PTR ; Compare queue to NULL
    jz .emptyQueue            ; Jump to emptyQueue if it's empty

    ; Retrieve the element from the first node
    mov ebx, [eax]            ; Load *queue (the head of the queue)
    mov eax, [ebx]            ; Load the element from the first node (node->elem)

    ; Update *queue to point to the next node (the new head)
    mov edx, [ebp+8]          ; Load the address of queue
    mov [edx], ebx            ; Set *queue to the address of the next node

.emptyQueue:
    ; Function epilogue:
    leave
    ret
