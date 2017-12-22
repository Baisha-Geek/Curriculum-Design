#ifndef COURSE_H
#define COURSE_H
#include <QString>
#include <QList>

class course
{
public:
    QString code,
            name;

    float examGrades = 0,
          ordGrades = 0,
          synGrades = 0,
          credit = 0;

    bool rebuild = 0;
};

#endif // COURSE_H
