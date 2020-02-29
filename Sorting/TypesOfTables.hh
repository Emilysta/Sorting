#pragma once
#include "Template.hh"
/*****************************************************************/
/*!
 * \file TypesOfTables.hh
 * \brief Plik zawiera instancje klasy Tables: 
 *  -Tables10k
 *  -Tables50k
 *  -Tables100k
 *  -Tables500k
 *  -Tables1M
 */
    using Tables5 = Tables<int,5>; //Testowa 10 tablic po 100 elementow
    using Tables10k = Tables<int,10000>;
    using Tables50k = Tables<int,50000>;
    using Tables100k = Tables<int,100000>;
    using Tables500k = Tables<int,500000>;
    using Tables1M = Tables<int,1000000>;

