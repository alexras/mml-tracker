#ifndef MMLTRACKER_INSTRUMENT_H
#define MMLTRACKER_INSTRUMENT_H

class Instrument {
public:
  // Gets the MML command corresponding to the instrument.
  std::string getMML() const = 0;
};

#endif // MMLTRACKER_INSTRUMENT_H
