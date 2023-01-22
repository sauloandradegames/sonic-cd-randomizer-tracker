// Segment.cpp
// Chain list implementation for Segments

#include "Segment.h"
#include "Stage.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUCTORS ---------------------------*/
Segment::Segment()
{
    head = NULL;
    curr = NULL;
    prev = NULL;
    for (Stage* i : index)
    {
        i = NULL;
    }
    num_stages = 0;
}

/*----------------------- METHODS: GET AND SET -----------------------*/
Stage* Segment::getHead()
{
    /* Returns the head of the list (Stage) */
    return head;
}

Stage* Segment::getCurr()
{
    /* Returns current stage in the segment */
    return curr;
}

Stage* Segment::getPrev()
{
    /* Returns previous stage in the segment */
    return prev;
}

int Segment::getNumStages()
{
    /* Returns how many stages are in the current segment*/
    return num_stages;
}

void Segment::setHead(Stage* target)
{
    /* Set "target" as the head of the list */
    head = target;
}

void Segment::setCurr(Stage* target)
{
    /* Set "target" as the current stage in the segment */
    curr = target;
}

void Segment::setPrev(Stage* target)
{
    /* Set "target" as the previous stage in the segment */
    prev = target;
}

Stage* Segment::getStageByIndex(int i)
{
    /* Returns stage stored in index[i] */
    return index[i];
}

void Segment::increaseNumStages()
{
    /* Increase num_stages by 1 */
    num_stages++;
}

void Segment::decreaseNumStages()
{
    /* Decrease num_stages by 1*/
    num_stages--;
}

/*-------------------------- METHODS: CRUD ---------------------------*/
int Segment::insert(int goal, int new_stage)
{
    /* Add "new_stage" to the segment, according to "goal"
     * Sort segment, if necessary
     * "goal" can be:
     * - 0: Stage clear (goal)
     * - 1: Time travel (past)
     * - 2: Time travel (future)
     * "new_stage" should be an integer for stage identifier
     * Return 0 (success) or -1 (failure)
    */

    Stage *toInsert; // New stage to be added to the segment
    int ic; // Sort procedure: index for current
    int ip; // Sort procedure: index for previous

    // Try to find "new_stage" in the current segment
    toInsert = search(new_stage);

    // Check if first time entering "new_stage"
    if (toInsert == NULL)
    {
        /* First time entering "new_stage" */
        toInsert = new Stage(new_stage);

        // If list is empty, insert new_stage in the head
        if (isEmpty() == 0)
        {
            head = toInsert;
            index[getNumStages()] = toInsert;
            increaseNumStages();

            setCurr(head);
            return 0;
        }

        // If not, check goal to insert
        // 1. From current stage, point to "toInsert" from one of three pointers
        // 2. Update index
        // 3. Update previous stage: advance to old current
        // 4. Update current stage: advance to "new_stage" (a.k.a toInsert)
        // 5. Update num_stages counter: increment it
        switch(goal)
        {
            case(0): // Stage Clear (Goal)
                getCurr()->setGoal(toInsert);
                index[getNumStages()] = toInsert;
                setPrev(getCurr());
                setCurr(toInsert);
                increaseNumStages();
                return 0;
            case(1): // Time Travel (Past)
                getCurr()->setPast(toInsert);
                index[getNumStages()] = toInsert;
                setPrev(getCurr());
                setCurr(toInsert);
                increaseNumStages();
                return 0;
            case(2): // Time Travel (Future)
                getCurr()->setFuture(toInsert);
                index[getNumStages()] = toInsert;
                setPrev(getCurr());
                setCurr(toInsert);
                increaseNumStages();
                return 0;
            default: // Error: invalid goal
                cout << "ERROR: Invalid goal" << endl;
                return -1;
        }
    }
    else
    {
        /* Revisiting "new_stage" */
        // Update pointers according to "goal"
        // 1. From current stage, point to "toInsert" from one of three pointers
        // 2. Update previous stage: advance to old current
        // 3. Update current stage: advance to "new_stage" (a.k.a toInsert)
        switch(goal)
        {
            case(0): // Stage Clear (Goal)
                getCurr()->setGoal(toInsert);
                setPrev(getCurr());
                setCurr(toInsert);
                return 0;
            case(1): // Time Travel (Past)
                getCurr()->setPast(toInsert);
                setPrev(getCurr());
                setCurr(toInsert);
                return 0;
            case(2): // Time Travel (Future)
                getCurr()->setFuture(toInsert);
                setPrev(getCurr());
                setCurr(toInsert);
                return 0;
            default: // Error: invalid goal
                cout << "ERROR: Invalid goal" << endl;
                return -1;
        }

    }
    return -1;
}

void Segment::clearSegment()
{
    /* Remove all stages from the segment, clearing it */
    int temp = getNumStages();
    for (int i = 0; i < temp; i++)
    {
        delete index[i];
        decreaseNumStages();
    }
    head = NULL;
}

Stage* Segment::search(int value)
{
    /* Search for any stage in the list where (stage.name == value)
     * Return a pointer to Stage (if any) or NULL (if no stage found)
    */

    // Check if list is empty
    if (isEmpty() != 0)
    {
        // Run through index array until find
        for (int i = 0; i < getNumStages(); i++)
        {
            if (index[i] != NULL)
            {
                if (index[i]->getName() == value)
                {
                    return index[i];
                }
            }
        }
        return NULL;
    }
    return NULL;
}

void Segment::swap(int a, int b)
{
    /* Swap stages a and b in the index array */
    // NEVER SWAP ANY index WITH 0
    if (a != 0 && b != 0)
    {
        Stage *sa = index[a];
        Stage *sb = index[b];

        index[a] = sb;
        index[b] = sa;
    }
}

int Segment::isEmpty()
{
    /* Check if this list is empty
     * Return 0 (List is empty) or -1 (List not empty)
     */
    if (head == NULL)
    {
        return 0;
    }
    return -1;
}