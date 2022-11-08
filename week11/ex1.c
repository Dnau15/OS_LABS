#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct Page {
    int id;
    int bits[8];
} Page;

void shift(Page * page);

void shift_all(Page * memory, int page_frames_count, int except_id);

int get_memory_index(Page * memory, int frames_count, int page_id);

int get_value(Page page);

int get_free_index(Page * memory, int frames_count);

int main(int argc, char *argv[]) {
    int page_id = 0;
    int hits = 0;
    int miss = 0;
    
    int page_frames_count = atoi(argv[1]);
    FILE * file = fopen("input.txt", "r");

    Page memory[page_frames_count];
    for (int i = 0;i < page_frames_count;i++){
        memory[i].id = -1;
    }
    
    while(fscanf(file, "%d", &page_id) > 0) {
        int index = get_memory_index(memory, page_frames_count, page_id);
        if (index != -1) hits++;
        else {
            Page page = {.id = page_id};
            index = get_free_index(memory, page_frames_count);
            memory[index] = page;
            miss++;
        }
        
        shift(&memory[index]);
        memory[index].bits[7] = 1; 
        shift_all(memory, page_frames_count, index);

    }
    printf(
        "Hit/Miss ratio: %f \n",
        (double)hits / (double)miss
    );
    return 0;
}

int get_memory_index(Page * memory, int frames_count, int page_id) {
    for(int i = 0; i < frames_count; i++) 
        if (memory[i].id == page_id) 
            return i;

    return -1;
}


int get_value(Page page) {
    int value = 0;
    for(int i = 0; i < 8; i++) 
        if (page.bits[i] != 0)
            value += (int)pow(2, i * page.bits[i]);
    return value;
}


int get_free_index(Page * memory, int frames_count) {
    for(int i = 0; i < frames_count; i++) 
    {
        if (memory[i].id == -1) return i;
    }
        
    int min_index = 0;
    int min_value = get_value(memory[min_index]);
    for(int i = 0; i < frames_count; i++) {
        int value = get_value(memory[i]);
        if (min_value > value) {
            min_value = value;
            min_index = i;
        }
    }

    return min_index;
} 

void shift(Page * page) {
    for(int i = 0; i < 8 - 1; i++)
        page->bits[i] = page->bits[i + 1];
    page->bits[8 - 1] = 0;
}

void shift_all(Page * memory, int page_frames_count, int id) {
    for(int i = 0; i < page_frames_count - 1; i++)
        if (i != id && memory[i].id != -1) 
            shift(&memory[i]);
}
