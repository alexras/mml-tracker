#ifndef MMLTRACKER_TRACK_H
#define MMLTRACKER_TRACK_H

#include <stdint.h>
#include <vector>

class Note;

class Track {
public:
  Track(uint32_t trackID);

  uint32_t getTrackID() const;

  void setLength(uint32_t length);
  uint32_t getLength() const;

  const Note* getNotes() const;

  void addNote(Note* note, uint32_t position);



private:
  const uint32_t trackID;

  uint32_t length;

  std::vector<Note*> notes;
};

#endif // MMLTRACKER_TRACK_H
