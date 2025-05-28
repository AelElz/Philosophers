/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-azha <ael-azha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:24:58 by ael-azha          #+#    #+#             */
/*   Updated: 2025/05/28 12:56:49 by ael-azha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval tv;
	
	if (gettimeofday(&tv, NULL) == 0)
	{
		printf("Seconds: %ld\n", tv.tv_sec);
		printf("Microseconds: %ld\n", tv.tv_usec);
	}
	else
		perror("gettimeofday failed\n");
}
