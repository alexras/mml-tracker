#include <QString>

#include "PlatformInfo.h"
#include "Sequence.h"
#include "Song.h"
#include "SongFactory.h"
#include "TrackBank.h"

SongFactory::SongFactory(PlatformInfo& _platformInfo,
                         PatternFactory& _patternFactory)
  : platformInfo(_platformInfo), patternFactory(_patternFactory) {
}

Song* SongFactory::newSong() {
  TrackBank* trackBank = new TrackBank();

  Sequence* sequence = new Sequence(*trackBank, patternFactory);

  Song* song = new Song(platformInfo);
  song->setSequence(sequence);
  song->setTrackBank(trackBank);

  return song;
}
