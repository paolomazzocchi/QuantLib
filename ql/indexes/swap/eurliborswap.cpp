/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006, 2007, 2008 Ferdinando Ametrano
 Copyright (C) 2006 Chiara Fornarola

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

#include <ql/indexes/swap/eurliborswap.hpp>
#include <ql/indexes/ibor/eurlibor.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/time/daycounters/thirty360.hpp>
#include <ql/currencies/europe.hpp>

using boost::shared_ptr;

namespace QuantLib {

    EurLiborSwapIsdaFixA::EurLiborSwapIsdaFixA(
                                        const Period& tenor,
                                        const Handle<YieldTermStructure>& h)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIsdaFixA", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
               tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, h)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, h))) {}

    EurLiborSwapIsdaFixA::EurLiborSwapIsdaFixA(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& forwarding,
                                const Handle<YieldTermStructure>& discounting)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIsdaFixA", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, forwarding)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, forwarding)),
                discounting) {}

    EurLiborSwapIsdaFixB::EurLiborSwapIsdaFixB(
                                        const Period& tenor,
                                        const Handle<YieldTermStructure>& h)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIsdaFixB", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, h)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, h))) {}

    EurLiborSwapIsdaFixB::EurLiborSwapIsdaFixB(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& forwarding,
                                const Handle<YieldTermStructure>& discounting)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIsdaFixB", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, forwarding)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, forwarding)),
                discounting) {}

    EurLiborSwapIfrFix::EurLiborSwapIfrFix(
                                        const Period& tenor,
                                        const Handle<YieldTermStructure>& h)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIfrFix", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, h)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, h))) {}

    EurLiborSwapIfrFix::EurLiborSwapIfrFix(
                                const Period& tenor,
                                const Handle<YieldTermStructure>& forwarding,
                                const Handle<YieldTermStructure>& discounting)
    : SwapIndex(EURCurrency(),
                "EurLiborSwapIfrFix", // familyName
                tenor,
                Thirty360(Thirty360::BondBasis), // fixedLegDaycounter
                2, // settlementDays
                TARGET(),
                1*Years, // fixedLegTenor
                ModifiedFollowing, // fixedLegConvention
                tenor > 1*Years ?
                    shared_ptr<IborIndex>(new EURLibor(6*Months, forwarding)) :
                    shared_ptr<IborIndex>(new EURLibor(3*Months, forwarding)),
                discounting) {}

}
