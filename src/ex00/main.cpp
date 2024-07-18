/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:14:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/07/18 19:24:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Subject
 *Observe que classes de exceção não precisam ser projetadas em
Forma Canônica Ortodoxa. Mas todas as outras classes precisam.

- Vamos projetar um pesadelo artificial de escritórios, corredores, formulários e filas de espera.
Parece divertido? Não? Que pena.


 */

// exceptions
#include <iostream>
using namespace std;

int main () {
  try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << endl;
  }
  return 0;
}
