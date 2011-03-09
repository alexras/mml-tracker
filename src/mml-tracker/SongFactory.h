#ifndef MMLTRACKER_SONG_FACTORY_H
#define MMLTRACKER_SONG_FACTORY_H

class PatternFactory;
class PlatformInfo;
class Song;

class SongFactory {
public:
  SongFactory(PlatformInfo& platformInfo, PatternFactory& patternFactory);
  Song* newSong();

private:
  PlatformInfo& platformInfo;
  PatternFactory& patternFactory;
};

#endif // MMLTRACKER_SONG_FACTORY_H
