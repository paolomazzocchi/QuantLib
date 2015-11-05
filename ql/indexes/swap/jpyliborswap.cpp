/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2008, 2011 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/indexes/swap/jpyliborswap.hpp>
#include <ql/indexes/ibor/jpylibor.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/daycounters/actualactual.hpp>
#include <ql/currencies/asia.hpp>

using boost::shared_ptr;

namespace QuantLib {

    JpyLiborSwapIsdaFixAm::JpyLiborSwapIsdaFixAm(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& h)
    : SwapIndex(JPYCurrency(),
                "JpyLiborSwapIsdaFixAm", // familyName
                tenor,
                ActualActual(ActualActual::ISDA), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                6*Months, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                boost::shared_ptr<IborIndex>(new JPYLibor(6*Months, h))) {}

    JpyLiborSwapIsdaFixAm::JpyLiborSwapIsdaFixAm(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& forwarding,
                                const Handle<YieldTermStructure>& discounting)
    : SwapIndex(JPYCurrency(),
                "JpyLiborSwapIsdaFixAm", // familyName
                tenor,
                ActualActual(ActualActual::ISDA), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                6*Months, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                shared_ptr<IborIndex>(new JPYLibor(6*Months, forwarding)),
                discounting) {}

    JpyLiborSwapIsdaFixPm::JpyLiborSwapIsdaFixPm(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& h)
    : SwapIndex(JPYCurrency(),
                "JpyLiborSwapIsdaFixPm", // familyName
                tenor,
                ActualActual(ActualActual::ISDA), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                6*Months, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                boost::shared_ptr<IborIndex>(new JPYLibor(6*Months, h))) {}

    JpyLiborSwapIsdaFixPm::JpyLiborSwapIsdaFixPm(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& forwarding,
                                const Handle<YieldTermStructure>& discounting)
    : SwapIndex(JPYCurrency(),
                "JpyLiborSwapIsdaFixPm", // familyName
                tenor,
                ActualActual(ActualActual::ISDA), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                6*Months, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                shared_ptr<IborIndex>(new JPYLibor(6*Months, forwarding)),
                discounting) {}

}
