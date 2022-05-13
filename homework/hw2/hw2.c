#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 64

typedef struct course_type* course_type_pointer;
typedef struct course_type
{   //course's struct
    char name[NAME_LENGTH];
    course_type_pointer next;
    course_type_pointer pre;
}course;
course** Course;

typedef struct node
{   //save the course's information
    int ID;
    int pre;
    int next;
}nodes;

course* getcourse(int courseCNT);
void link_the_course(int courseCNT,nodes* course_info);
void read_course(course_type_pointer start);

int main()
{
    int courseCNT;
    scanf("%d",&courseCNT);
    Course = (course**)malloc(courseCNT*sizeof(course*));
    course* start = getcourse(courseCNT);
    read_course(start);
    return 0;
}

course_type_pointer getcourse(int courseCNT)
{   //get the course ID NextCourse PreCourse & CourseName
    int i;
    nodes* course_info = (nodes*)malloc(courseCNT*sizeof(nodes));
    for(i=0;i<courseCNT;i++)
    {
        Course[i] = (course*)malloc(sizeof(course));
        //initiallize all Course's next & pre
        Course[i]->next = NULL;
        Course[i]->pre = NULL;
        scanf("%d %d %d %s",&course_info[i].ID,&course_info[i].next,&course_info[i].pre,Course[i]->name);
    }
    link_the_course(courseCNT,course_info);
    course_type_pointer temp = NULL;
    for(i=0;i<courseCNT;i++)
    {   //Find the current Course
        if(course_info[i].ID == 0)
        temp = Course[i];
    }
    link_the_course(courseCNT,course_info);
    return temp;
}

void link_the_course(int courseCNT,nodes* course_info)
{   //link the Course's NextCourse & PreCourse
    int i,j;
    for(i=0;i<courseCNT;i++)
    {
        for(j=0;j<courseCNT;j++)
        {
            if(course_info[i].next == course_info[j].ID)
            {   //link the nextCourse
                Course[i]->next = Course[j];
            }
            if(course_info[i].pre == course_info[j].ID)
            {   //link the preCourse
                Course[i]->pre = Course[j];
            }
        }
    }
}

void read_course(course_type_pointer start)
{
    char input;
    int isdo = 0;
    course_type_pointer temp = start;
    do
    {
        if(isdo)
        {
            switch(input)
            {
                case 'n':
                    if(temp->next == NULL)
                    {
                        printf("There is no next course.\n");
                    }
                    else
                    {
                        temp = temp->next;
                    }
                    break;
                case 'p':
                    if(temp->pre == NULL)
                    {
                        printf("There is no previous course.\n");
                    }
                    else
                    {
                        temp = temp->pre;
                    }
                    break;
            }
        }
        printf("Current Course: %s\n",temp->name);
        printf("[n] Next course. [p] Prior course [q] Quit:");
        scanf("\n%c",&input);
        isdo = 1;
    } while (input!='q');
}
