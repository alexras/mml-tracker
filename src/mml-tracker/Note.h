#ifndef MMLTRACKER_NOTE_H
#define MMLTRACKER_NOTE_H

class Note {
public:
  Note();

private:
  uint64_t volume;
  std::list<Effect*> effects;
};

#endif // MMLTRACKER_NOTE_H
