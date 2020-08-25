//=============================================================================
//  MuseScore
//  Music Composition & Notation
//
//  Copyright (C) 2020 MuseScore BVBA and others
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License version 2.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FIT-0NESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//=============================================================================
#ifndef MU_DOMAIN_NOTATION_INOTATIONPARTS_H
#define MU_DOMAIN_NOTATION_INOTATIONPARTS_H

#include "notationtypes.h"
#include "scenes/instruments/instrumentstypes.h"
#include "async/notification.h"
#include "async/channel.h"

namespace mu {
namespace domain {
namespace notation {
class INotationParts
{
public:
    virtual ~INotationParts() = default;

    virtual PartList partList() const = 0;
    virtual InstrumentList instrumentList(const QString& partId) const = 0;
    virtual StaffList staffList(const QString& partId, const QString& instrumentId) const = 0;

    virtual void setInstruments(const std::vector<QString>& instrumentTemplateIds) = 0;
    virtual void setPartVisible(const QString& partId, bool visible) = 0;
    virtual void setInstrumentVisible(const QString& partId, const QString& instrumentId, bool visible) = 0;
    virtual void setStaffVisible(int staffIndex, bool visible) = 0;
    virtual void setVoiceVisible(int staffIndex, int voiceIndex, bool visible) = 0;
    virtual void setStaffType(int staffIndex, StaffType type) = 0;
    virtual void setCutaway(int staffIndex, bool value) = 0;
    virtual void setSmallStaff(int staffIndex, bool value) = 0;

    virtual void removeParts(const std::vector<QString>& partsIds) = 0;
    virtual void removeInstruments(const QString& partId, const std::vector<QString>& instrumentIds) = 0;
    virtual void removeStaves(const std::vector<int>& stavesIndexes) = 0;

    virtual void movePart(const QString& partId, const QString& beforePartId) = 0;
    virtual void moveInstrument(const QString& instrumentId, const QString& fromPartId, const QString& toPartId,
                                const QString& beforeInstrumentId) = 0;
    virtual void moveStaff(int staffIndex, int beforeStaffIndex) = 0;

    virtual const Staff* appendStaff(const QString& partId, const QString& instrumentId) = 0;
    virtual const Staff* appendLinkedStaff(int staffIndex) = 0;

    virtual void replaceInstrument(const QString& partId, const QString& instrumentId,const QString& instrumentTemplateId) = 0;

    virtual async::Channel<const Part*> partChanged() const = 0;
    virtual async::Channel<const Instrument*> instrumentChanged() const = 0;
    virtual async::Channel<const Staff*> staffChanged() const = 0;
    virtual async::Notification partsChanged() const = 0;
};
}
}
}

#endif // MU_DOMAIN_NOTATION_INOTATIONPARTS_H