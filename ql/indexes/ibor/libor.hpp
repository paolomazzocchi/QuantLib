/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2007 Ferdinando Ametrano
 Copyright (C) 2007 Chiara Fornarola
 Copyright (C) 2005, 2006, 2008 StatPro Italia srl
 Copyright (C) 2015 Paolo Mazzocchi

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

/*! \file libor.hpp
    \brief base class for BBA LIBOR indexes
*/

#ifndef quantlib_libor_hpp
#define quantlib_libor_hpp

#include <ql/indexes/iborindex.hpp>

namespace QuantLib {

    //! base class for all ICE LIBOR indexes but the EUR, O/N, and S/N ones
    /*! LIBOR fixed by ICE.

        See <https://www.theice.com/iba/libor>.
    */
    class Libor : public IborIndex {
      public:
QL_DEPRECATED
        Libor(const std::string& familyName,
              const Period& tenor,
              Natural settlementDays,
              const Currency& currency,
              const Calendar& financialCenterCalendar,
              const DayCounter& dayCounter,
              const Handle<YieldTermStructure>& h =
                                    Handle<YieldTermStructure>());
        Libor(const Currency& currency,
              const Period& tenor,
              const DayCounter& dayCounter,
              Natural settlementDays,
              const Calendar& financialCenterCalendar,
              const Handle<YieldTermStructure>& h =
                                   Handle<YieldTermStructure>());
        Libor(const Currency& currency,
              const Period& tenor,
              const DayCounter& dayCounter,
              Natural settlementDays,
              const Calendar& financialCenterCalendar,
              const std::string& familyName = "Libor",
              const Handle<YieldTermStructure>& h =
                                   Handle<YieldTermStructure>());
        /*! \name Date calculations

            see https://www.theice.com/iba/libor
            @{
        */
        Date valueDate(const Date& fixingDate) const;
        Date maturityDate(const Date& valueDate) const;
        // @}
        //! \name Other methods
        //@{
        boost::shared_ptr<IborIndex> clone(
                                   const Handle<YieldTermStructure>& h) const;
        // @}
        //! \name Other inspectors
        //@{
        Calendar jointCalendar() const;
        // @}
      private:
        Calendar financialCenterCalendar_;
        Calendar jointCalendar_;
    };

    //! base class for all O/N-S/N ICE LIBOR indexes but the EUR ones
    /*! One day deposit LIBOR fixed by ICE.

        See <https://www.theice.com/iba/libor>.
    */
    class DailyTenorLibor : public IborIndex {
      public:
QL_DEPRECATED
        DailyTenorLibor(const std::string& familyName,
                        Natural settlementDays,
                        const Currency& currency,
                        const Calendar& financialCenterCalendar,
                        const DayCounter& dayCounter,
                        const Handle<YieldTermStructure>& h =
                                    Handle<YieldTermStructure>());
        DailyTenorLibor(const Currency& currency,
                        const DayCounter& dayCounter,
                        Natural settlementDays,
                        const Calendar& financialCenterCalendar,
                        const Handle<YieldTermStructure>& h =
                                    Handle<YieldTermStructure>());
        DailyTenorLibor(const Currency& currency,
                        const DayCounter& dayCounter,
                        Natural settlementDays,
                        const Calendar& financialCenterCalendar,
                        const std::string& familyName = "Libor",
                        const Handle<YieldTermStructure>& h =
                                    Handle<YieldTermStructure>());

    };

}

#endif
