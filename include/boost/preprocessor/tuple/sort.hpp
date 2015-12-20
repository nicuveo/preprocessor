//
// Copyright Antoine Leblanc 2015
// http://nauths.fr
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BOOST_PREPROCESSOR_TUPLE_SORT_HPP
# define BOOST_PREPROCESSOR_TUPLE_SORT_HPP

# include <boost/preprocessor/config/config.hpp>
# if BOOST_PP_VARIADICS



#  include <boost/preprocessor/array/lower_bound.hpp>
#  include <boost/preprocessor/array/to_tuple.hpp>
#  include <boost/preprocessor/array/insert.hpp>
#  include <boost/preprocessor/tuple/elem.hpp>
#  include <boost/preprocessor/tuple/size.hpp>



/*
** BOOST_PP_TUPLE_SORT
** Sorts the given PP_TUPLE.
** _U variants remove duplicates.
** _D variants use the next available PP_WHILE iteration
*/

#  define BOOST_PP_TUPLE_SORT(A)       BOOST_PP_ARRAY_TO_TUPLE(BOOST_PP_TUPLE_ELEM(3,2, BOOST_PP_WHILE(                 BOOST_PP_TS_PRED_0, BOOST_PP_TS_OP_0,   (A,0,(0,(0))))))
#  define BOOST_PP_TUPLE_SORT_U(A)     BOOST_PP_ARRAY_TO_TUPLE(BOOST_PP_TUPLE_ELEM(3,2, BOOST_PP_WHILE(                 BOOST_PP_TS_PRED_0, BOOST_PP_TS_OP_0_U, (A,0,(0,(0))))))
#  define BOOST_PP_TUPLE_SORT_D(D,A)   BOOST_PP_ARRAY_TO_TUPLE(BOOST_PP_TUPLE_ELEM(3,2, BOOST_PP_CAT(BOOST_PP_WHILE_,D)(BOOST_PP_TS_PRED_0, BOOST_PP_TS_OP_0,   (A,0,(0,(0))))))
#  define BOOST_PP_TUPLE_SORT_U_D(D,A) BOOST_PP_ARRAY_TO_TUPLE(BOOST_PP_TUPLE_ELEM(3,2, BOOST_PP_CAT(BOOST_PP_WHILE_,D)(BOOST_PP_TS_PRED_0, BOOST_PP_TS_OP_0_U, (A,0,(0,(0))))))



/*
** Internal helpers
*/


#  define BOOST_PP_TS_GETR(   D,R,I,X) R
#  define BOOST_PP_TS_MERGE_R(D,R,I,X) BOOST_PP_IF(BOOST_PP_LESS_D(D,X, BOOST_PP_ARRAY_ELEM(I, R)), BOOST_PP_ARRAY_INSERT_D,    BOOST_PP_TS_GETR)(D,R,I,X)
#  define BOOST_PP_TS_MERGE_U(D,R,I,X) BOOST_PP_IF(BOOST_PP_LESS_D(D,I, BOOST_PP_ARRAY_SIZE(   R)), BOOST_PP_TS_MERGE_R, BOOST_PP_ARRAY_INSERT_D)(D,R,I,X)

#  define BOOST_PP_TS_PRED_0(D,S)   BOOST_PP_TS_PRED_1(D, BOOST_PP_TUPLE_ELEM(3,0,S), BOOST_PP_TUPLE_ELEM(3,1,S))
#  define BOOST_PP_TS_PRED_1(D,T,I) BOOST_PP_LESS_D(D, I, BOOST_PP_TUPLE_SIZE(T))

#  define BOOST_PP_TS_OP_0(  D,S)       BOOST_PP_TS_OP_1(  D, BOOST_PP_TUPLE_ELEM(3,0,S), BOOST_PP_TUPLE_ELEM(3,1,S), BOOST_PP_TUPLE_ELEM(3,2,S))
#  define BOOST_PP_TS_OP_0_U(D,S)       BOOST_PP_TS_OP_1_U(D, BOOST_PP_TUPLE_ELEM(3,0,S), BOOST_PP_TUPLE_ELEM(3,1,S), BOOST_PP_TUPLE_ELEM(3,2,S))
#  define BOOST_PP_TS_OP_1(  D,T,I,R)   BOOST_PP_TS_OP_2(  D, T, I, R, BOOST_PP_TUPLE_ELEM(I, T))
#  define BOOST_PP_TS_OP_1_U(D,T,I,R)   BOOST_PP_TS_OP_2_U(D, T, I, R, BOOST_PP_TUPLE_ELEM(I, T))
#  define BOOST_PP_TS_OP_2(  D,T,I,R,X) (T, BOOST_PP_INC(I), BOOST_PP_ARRAY_INSERT_D(D, R, BOOST_PP_ARRAY_LOWER_BOUND_D(D,R,X), X))
#  define BOOST_PP_TS_OP_2_U(D,T,I,R,X) (T, BOOST_PP_INC(I),     BOOST_PP_TS_MERGE_U(D, R, BOOST_PP_ARRAY_LOWER_BOUND_D(D,R,X), X))



# endif /* BOOST_PP_VARIADICS */

#endif /* !BOOST_PREPROCESSOR_TUPLE_SORT_HPP */
