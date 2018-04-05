#ifndef LABEL_H
#define LABEL_H

#include <iostream>

class Label {
  private:
    static unsigned _counter;
    unsigned _number;

  public:
    Label();
    unsigned number() const;
};

std::ostream &operator <<(std::ostream &os, const Label &label);

#endif
