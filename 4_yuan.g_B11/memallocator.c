#include "memallocator.h"

static struct {
    descriptor_t* head;
    int fullsize;
} mem_list = { (descriptor_t*)NULL, 0 };//空链表


int meminit(void* pMemory, int size) // 使用内存块 pMemory 初始化内存系统。
{
    if (!pMemory || size <= memgetminimumsize())
    {
        return 0;
    }
    else
    {
        mem_list.head = (descriptor_t*)pMemory;
        mem_list.fullsize = size;
        mem_list.head->prev = NULL;
        mem_list.head->next = NULL;
        mem_list.head->key = 1;
        mem_list.head->size = size - memgetblocksize();
        
    }
    return 1;
}

void* memalloc(int size)// 分配大小为“size”的内存块。  // 成功返回指向内存块的指针，否则返回0
{
    void* ptr = NULL;
    descriptor_t* temp;
    int descr_size = memgetblocksize();
    if (size <= 0 || mem_list.head == NULL)
    {
        return NULL;
    }

    temp = mem_list.head;

    while (!(temp->key == 1) || !(temp->size >= size))//如果temp->key 
    {
        if (!temp->next)
        {
            return NULL;
        }
        else
        {
            temp = temp->next;
        }
    }

    if (temp->size > size + descr_size) //if size of found block > required size
    {
        //describing right block  //描述右块
        descriptor_t* right = (descriptor_t*)((char*)temp + size + descr_size);
        right->size = temp->size - descr_size - size;
        right->next = temp->next;
        right->prev = temp;
        right->key = 1;

        if (temp->next)
        {
            temp->next->prev = right;
        }
        //描述左块

        temp->size = size;
        temp->next = right;
        temp->key = 0;
    }
    else
    {
        //temp->key = 0;
    }
    ptr = (void*)((char*)temp + descr_size);

    return ptr;
}

void memfree(void* p)// free 释放先前由 memalloc 分配的内存
{
    descriptor_t* free_p = NULL;
    descriptor_t* temp = NULL; // 如果可以将 2 个空闲块合并为 1 个，则使用此指针
    int descr_size = memgetblocksize();

    if (p && mem_list.head)
    {
        free_p = (descriptor_t*)((char*)p - descr_size);

        if (free_p >= mem_list.head && free_p <= mem_list.head + mem_list.fullsize && !(free_p->key))//如果块是从我们的内存列表中取出的
        {
            free_p->key = 1;

            if (free_p->next && free_p->next->key) //如果可以与右块合并：
            {
                //describing new "big" block
                temp = free_p; //pointer to left block
                temp->size = descr_size + temp->size + temp->next->size;

                if (temp->next->next)
                {
                    temp->next->next->prev = temp;
                    temp->next = temp->next->next;
                }
                else
                {
                    temp->next = NULL;
                }

                if (temp->prev)
                {
                    temp->prev->next = temp;
                }
                else
                {
                    temp->prev = NULL;
                }
            }

            if (free_p->prev && free_p->prev->key)//如果可以与左块合并
            {

                temp = free_p->prev;
                if (temp->next)
                {
                    temp->size = descr_size + temp->size + temp->next->size;
                }

                if (temp->next)
                {
                    if (temp->next->next)
                    {
                        temp->next->next->prev = temp;
                        temp->next = temp->next->next;
                    }
                    else
                    {
                        temp->next = NULL;
                    }
                }

            }
        }
    }
}

void memdone()  // 你可以在这里实现内存泄漏检查
{
    descriptor_t* cur = mem_list.head;
    int memsum = 0;

    while (cur)
    {
        if (cur->key)
        {
            memsum += cur->size;
        }
        cur = cur->next;
    }
}

int memgetminimumsize() {// 返回分配 0 字节块的内存池的最小大小（以字节为单位）
    return sizeof(descriptor_t);
}

int memgetblocksize() {  // 返回每次分配的附加信息的字节大小
    return sizeof(descriptor_t);
}
