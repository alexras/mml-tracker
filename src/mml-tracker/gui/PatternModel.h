#ifndef MMLTRACKER_PATTERN_MODEL_H
#define MMLTRACKER_PATTERN_MODEL_H

#include <QAbstractTableModel>

#include "mml-tracker/Pattern.h"

class Pattern;
class Note;
class PlatformInfo;

class PatternModel : public QAbstractTableModel {
Q_OBJECT

public:
  enum NoteSubPart {
    NOTE_SUBPART_PITCH,
    NOTE_SUBPART_INSTRUMENT,
    NOTE_SUBPART_VOLUME,
    NOTE_SUBPART_COMMAND
  };

  static const int NUM_NOTE_SUBPARTS = 4;

  PatternModel(Pattern* pattern, const PlatformInfo& platformInfo,
               QObject* parent = NULL);

  int rowCount(const QModelIndex & parent) const;
  int columnCount(const QModelIndex & parent) const;
  QVariant data(const QModelIndex& index, int role) const;
  bool setData(const QModelIndex& index, const QVariant& value, int role);
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  Qt::ItemFlags flags(const QModelIndex& index) const;

  void setPattern(Pattern* pattern);
private:
  Pattern* pattern;
  const PlatformInfo& platformInfo;

  Note* getNote(const QModelIndex& index) const;
  NoteSubPart getNoteSubPart(const QModelIndex& index) const;
  Track* getTrack(const QModelIndex& index) const;
};

#endif // MMLTRACKER_PATTERN_MODEL_H
