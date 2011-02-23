#ifndef MMLTRACKER_TRACK_H
#define MMLTRACKER_TRACK_H

#include <stdint>
#include <vector>

class Track {
public:
  Track();
  
  void setLength(uint64_t length);
  uint64_t getLength() const;
  
  const Note* getNotes() const;
  
private:
  uint64_t length;
  
  std::vector<Note*> notes;
};

#endif // MMLTRACKER_TRACK_H
