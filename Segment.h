// Segment.h
// Header - Chain list implementation for Segments

#ifndef SEGMENT_H
#define SEGMENT_H

#include "Stage.h"

class Segment
{
    private:
/*---------------------------- ATTRIBUTES ----------------------------*/
        Stage *head; // Pointer for the first element of the list (head)
        Stage *curr; // Pointer for current stage in the segment
        Stage *prev; // Pointer for previous stage
        Stage *index[100]; // Array of pointers for indexing and search
        int num_stages; // Number of stages in the current Segment

    public:
/*--------------------------- CONSTRUCTORS ---------------------------*/
        Segment(); // Default constructor (Empty Segment)

/*----------------------- METHODS: GET AND SET -----------------------*/
        Stage* getHead(); // Returns the head of the list (Stage)
        Stage* getCurr(); // Returns current stage in the segment
        Stage* getPrev(); // Returns previous stage in the segment
        Stage* getStageByIndex(int i); // Returns stage stored in index[i]
        int getNumStages(); // Returns how many stages are in the current segment
        void setHead(Stage* target); // Set "target" as the head of the list
        void setCurr(Stage* target); // Set "target" as current stage in the segment
        void setPrev(Stage* target); // Set "target" as previous stage in the segment
        void increaseNumStages(); // Increase num_stages by 1
        void decreaseNumStages(); // Decrease num_stages by 1
/*-------------------------- METHODS: CRUD ---------------------------*/
        int insert(int goal, int new_stage); // Add "new_stage" to the segment, according to "goal"
        void clearSegment(); // Remove all stages from the segment
        Stage* search(int value); // Search for any Stage in the list where (stage.name == value)
        void swap(int index_a, int index_b); // Swap stages a and b in the index array
        int isEmpty(); // Is this list empty?
};

#endif // SEGMENT_H