//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2011-2016 Werner Schweer and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2
//  as published by the Free Software Foundation and appearing in
//  the file LICENSE.GPL
//=============================================================================

#ifndef __INSPECTOR_H__
#define __INSPECTOR_H__


#include "inspectorBase.h"
#include "inspectorElementBase.h"
#include "inspectorTextBase.h"
#include "inspectors/ui_inspector_break.h"
#include "inspectors/ui_inspector_sectionbreak.h"
#include "inspectors/ui_inspector_stafftypechange.h"
#include "inspectors/ui_inspector_vbox.h"
#include "inspectors/ui_inspector_tbox.h"
#include "inspectors/ui_inspector_hbox.h"
#include "inspectors/ui_inspector_articulation.h"
#include "inspectors/ui_inspector_spacer.h"
#include "inspectors/ui_inspector_segment.h"
#include "inspectors/ui_inspector_note.h"
#include "inspectors/ui_inspector_chord.h"
#include "inspectors/ui_inspector_rest.h"
#include "inspectors/ui_inspector_clef.h"
#include "inspectors/ui_inspector_timesig.h"
#include "inspectors/ui_inspector_keysig.h"
#include "inspectors/ui_inspector_volta.h"
#include "inspectors/ui_inspector_tuplet.h"
#include "inspectors/ui_inspector_accidental.h"
#include "inspectors/ui_inspector_tempotext.h"
#include "inspectors/ui_inspector_lyric.h"
#include "inspectors/ui_inspector_stafftext.h"
#include "inspectors/ui_inspector_slur.h"
#include "inspectors/ui_inspector_empty.h"
#include "inspectors/ui_inspector_text.h"
// #include "ui_inspector_fret.h"
#include "inspectors/ui_inspector_tremolo.h"
#include "inspectors/ui_inspector_caesura.h"
#include "inspectors/ui_inspector_bracket.h"
#include "inspectors/ui_inspector_iname.h"
#include "inspectors/ui_inspector_fermata.h"
#include "inspectors/ui_inspector_stem.h"

#include <QDockWidget>

class InspectorFormWidget;

namespace Ms {

class Score;
class Element;
class Note;
class Inspector;
class Segment;
class Chord;
class Clef;

//---------------------------------------------------------
//   InspectorElement
//---------------------------------------------------------

class InspectorElement : public InspectorElementBase {
      Q_OBJECT

   public:
      InspectorElement(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorBreak
//---------------------------------------------------------

class InspectorBreak : public InspectorBase {
      Q_OBJECT
      Ui::InspectorBreak b;

   public:
      InspectorBreak(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorSectionBreak
//---------------------------------------------------------

class InspectorSectionBreak : public InspectorBase {
      Q_OBJECT
      Ui::InspectorSectionBreak scb;

   public:
      InspectorSectionBreak(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorStaffTypeChange
//---------------------------------------------------------

class InspectorStaffTypeChange : public InspectorBase {
      Q_OBJECT
      Ui::InspectorStaffTypeChange sl;

   public:
      InspectorStaffTypeChange(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorVBox
//---------------------------------------------------------

class InspectorVBox : public InspectorBase {
      Q_OBJECT
      Ui::InspectorVBox vb;

   public:
      InspectorVBox(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorTBox
//---------------------------------------------------------

class InspectorTBox : public InspectorBase {
      Q_OBJECT
      Ui::InspectorTBox tb;

   public:
      InspectorTBox(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorHBox
//---------------------------------------------------------

class InspectorHBox : public InspectorBase {
      Q_OBJECT
      Ui::InspectorHBox hb;

   public:
      InspectorHBox(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorArticulation
//---------------------------------------------------------

class InspectorArticulation : public InspectorElementBase {
      Q_OBJECT
      Ui::InspectorArticulation ar;

   private slots:
      void propertiesClicked();

   public:
      InspectorArticulation(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorFermata
//---------------------------------------------------------

class InspectorFermata : public InspectorElementBase {
      Q_OBJECT
      Ui::InspectorFermata f;

   public:
      InspectorFermata(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorSpacer
//---------------------------------------------------------

class InspectorSpacer : public InspectorBase {
      Q_OBJECT
      Ui::InspectorSpacer sp;

   public:
      InspectorSpacer(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorRest
//---------------------------------------------------------

class InspectorRest : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorSegment s;
      Ui::InspectorRest    r;

      QPushButton* dot1;
      QPushButton* dot2;
      QPushButton* dot3;
      QPushButton* dot4;
      QPushButton* tuplet;

      void dotClicked(int n);

   private slots:
      void dot1Clicked();
      void dot2Clicked();
      void dot3Clicked();
      void dot4Clicked();
      void tupletClicked();

   public:
      InspectorRest(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorClef
//---------------------------------------------------------

class InspectorClef : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorSegment s;
      Ui::InspectorClef    c;
      Clef* otherClef;        // the courtesy clef for a main clef or viceversa
                              // used to keep in sync ShowCourtesy setting of both clefs
   protected:
      using InspectorBase::valueChanged;
      void valueChanged(int idx) override;

   public:
      InspectorClef(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorStem
//---------------------------------------------------------

class InspectorStem : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorStem s;

   public:
      InspectorStem(QWidget* parent);
//      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorTimeSig
//---------------------------------------------------------

class InspectorTimeSig : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorSegment s;
      Ui::InspectorTimeSig t;

   private slots:
      void propertiesClicked();

   public:
      InspectorTimeSig(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorKeySig
//---------------------------------------------------------

class InspectorKeySig : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorSegment s;
      Ui::InspectorKeySig k;

   public:
      InspectorKeySig(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   InspectorTuplet
//---------------------------------------------------------

class InspectorTuplet : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorTuplet t;

   public:
      InspectorTuplet(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorAccidental
//---------------------------------------------------------

class InspectorAccidental : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorAccidental a;

   public:
      InspectorAccidental(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorTremolo
//---------------------------------------------------------

class InspectorTremolo : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorTremolo g;

   public:
      InspectorTremolo(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorTempoText
//---------------------------------------------------------

class InspectorTempoText : public InspectorTextBase {
      Q_OBJECT

      Ui::InspectorTempoText tt;

   public:
      InspectorTempoText(QWidget* parent);
      virtual void postInit() override;
      };

//---------------------------------------------------------
//   InspectorLyric
//---------------------------------------------------------

class InspectorLyric : public InspectorTextBase {
      Q_OBJECT

      Ui::InspectorLyric l;

   private slots:

   public:
      InspectorLyric(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorLyric
//---------------------------------------------------------

class InspectorStaffText : public InspectorTextBase {
      Q_OBJECT

      Ui::InspectorStaffText s;

   private slots:
      void propertiesClicked();

   public:
      InspectorStaffText(QWidget* parent);
      virtual void setElement() override;
      };

//---------------------------------------------------------
//   Inspector
//---------------------------------------------------------

class Inspector : public QDockWidget {
      Q_OBJECT

      InspectorBase* ie = nullptr;
      Score* _score = nullptr;
      bool _inspectorEdit = false;    // set to true when an edit originates from
                              // within the inspector itself
      Element* oe = nullptr;
      bool oSameTypes = false;

   public slots:
      void update();

   protected:
      virtual void changeEvent(QEvent *event);
      void retranslate();

   signals:
      void propertyEditStarted(Element* element);
      void selectionChanged(const QList<Element*>& elementList);
      void layoutUpdateRequested();

   public:
      Inspector(QQmlEngine* engine, QWidget* parent = 0);
      void update(Score* s);

      Element* element() const;
      const QList<Element*>* el() const;
      void setInspectorEdit(bool val)     { _inspectorEdit = val;  }
      void setQmlEngine(QQmlEngine* qmlEngine) { m_qmlEngine = qmlEngine; }

      friend class InspectorScriptEntry;

   private:

      QQmlEngine* m_qmlEngine = nullptr;
      InspectorFormWidget* m_inspectorForm = nullptr;
      };

//---------------------------------------------------------
//   InspectorSlurTie
//---------------------------------------------------------

class InspectorSlurTie : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorSlur s;

   public:
      InspectorSlurTie(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorCaesura
//---------------------------------------------------------

class InspectorCaesura : public InspectorElementBase {
      Q_OBJECT

      Ui::InspectorCaesura c;

   public:
      InspectorCaesura(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorBracket
//---------------------------------------------------------

class InspectorBracket : public InspectorBase {
      Q_OBJECT

      Ui::InspectorBracket b;

   public:
      InspectorBracket(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorIname
//---------------------------------------------------------

class InspectorIname : public InspectorTextBase {
      Q_OBJECT

      Ui::InspectorIname i;

   public:
      InspectorIname(QWidget* parent);
      };

//---------------------------------------------------------
//   InspectorEmpty
//---------------------------------------------------------

class InspectorEmpty : public InspectorBase {
      Q_OBJECT

      Ui::InspectorEmpty e;

   public:
      InspectorEmpty(QWidget* parent);
      virtual QSize sizeHint() const override;
      };

extern void populatePlacement(QComboBox*);

} // namespace Ms
#endif
