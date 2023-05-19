<div align="center">
	<img src=".github/assets/jantar-filosofos.jpg" />
</div>

### Rules
> Global variables are forbidden!
> 
> Your(s) program(s) should take the following arguments: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
> - number_of_philosophers: The number of philosophers and also the number of forks.
> - time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation,
> they die.
> - time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
> - time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
> - number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
> 
> Each philosopher has a number ranging from 1 to number_of_philosophers.
> 
> Philosopher number 1 sits next to philosopher number number_of_philosophers.
> 
> Any other philosopher number N sits between philosopher number N - 1 and philosopher
> number N + 1.
> 
> About the logs of your program (Any state change of a philosopher must be formatted as follows):
> - timestamp_in_ms X has taken a fork
> - timestamp_in_ms X is eating
> - timestamp_in_ms X is sleeping
> - timestamp_in_ms X is thinking
> - timestamp_in_ms X died
> Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.
> 
> A displayed state message should not be mixed up with another message.
> 
> A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.
> 
> Again, philosophers should avoid dying!
<h3 align=center>
Mandatory
</h3>

> - Each philosopher should be a thread.
> - There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.
> - To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

### Functions Manual

  - <a href="https://man7.org/linux/man-pages/man3/usleep.3.html">usleep()</a> 
  - <a href="https://man7.org/linux/man-pages/man2/settimeofday.2.html">gettimeofday()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_create.3p.html">pthread_create()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_detach.3p.html">pthread_detach()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_join.3p.html">pthread_join()</a>
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html">pthread_mutex_init()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html">pthread_mutex_destroy()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3p.html">pthread_mutex_lock()</a> 
  - <a href="https://man7.org/linux/man-pages/man3/pthread_mutex_unlock.3p.html">pthread_mutex_unlock()</a> 


## usage

Git clone the project:
```sh
git 
```
To compile, use make
```sh
make
```
Run the program with the following arguments:
```sh
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philo_must_eat]
``` 

### Helpers

- https://github.com/srimant03/Dining-Philosophers-Problem

- https://www.youtube.com/watch?v=G0ZCndqb0xk

- https://www.youtube.com/watch?v=g9zEqwSZd4o

- http://cocic.cm.utfpr.edu.br/progconcorrente/doku.php?id=c_pthreads

- https://www.ibm.com/docs/pt-br/aix/7.3?topic=programming-using-mutexes

- https://wiki.inf.ufpr.br/maziero/doku.php?id=so:jantar_dos_filosofos

