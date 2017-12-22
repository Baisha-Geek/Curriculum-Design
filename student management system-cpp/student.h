#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <QList>
#include <course.h>

class student
{
public:
    QString id,
            name,
            clase,
            sex,
            age,
            dornum,
            telnum,
            average;

    QList <course> courses;

   // student();
   // ~student();
};

#endif // STUDENT_H
