// Copyright (c) 2012-2014 Eric M. Heien, Michael K. Sachs, John B. Rundle
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "Simulation.h"
#include <cmath>

#ifndef _SANITY_CHECK_H_
#define _SANITY_CHECK_H_

/*!
 Checks the values of the update field and CFF during the simulation to ensure
 they are within reason and stops the simulation if values are getting strange.
 What constitutes "reasonable values" is somewhat arbitrary, but here anything
 greater than 1e10 is unreasonable.
 */
class SanityCheck : public SimPlugin {
    public:
        virtual std::string name() const {
            return "Simulation value sanity check";
        };
        virtual void initDesc(const SimFramework *_sim) const;

        virtual SimRequest run(SimFramework *_sim);
        virtual void finish(SimFramework *_sim);

    private:
        std::vector<std::pair<BlockID, double> >    failed_cffs, failed_update_fields;

        bool assertCFFValueCorrectness(Simulation *sim);
        bool assertUpdateFieldCorrectness(Simulation *sim);
};

#endif
