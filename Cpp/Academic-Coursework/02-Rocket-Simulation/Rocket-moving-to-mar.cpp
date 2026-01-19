#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <limits>

/* Author: Usman O. Olanrewaju (Blu3 Sky) 
 * Title: Rocket-moving
 */
using namespace std;
int getRandomInt(int min, int max) {
	return min + (rand() % (max - min + 1));
}


	const long long DISTANCE_TO_MARS_KM = 2250000000;
	const int INITIAL_FUEL_LITERS = 50000;
	const int FUEL_CAPACITY_LITERS = 50000;
	const int MIN_DAILY_DIST_KM = 100000;
	const int MAX_DAILY_DIST_KM = 200000;
	const int MIN_FUEL_CONSUMPTION_L = 50;
	const int MAX_FUEL_CONSUMPTION_L = 1000;
	const int EXPECTED_MAX_DURATION_DAYS = 300;
	const int LOW_FUEL_WARNING_THRESHOLD = 500;

	void runMarsMission() {
		cout << "\n--- Starting Mars Mission Simulation (Question 2) ---\n";

		double currentFuel = INITIAL_FUEL_LITERS;
		long long distanceTraveled = 0;
		int missionDuration = 0;
		bool missionSuccess = false;
		bool missionOver = false;
		cout << "Initiating Mars Mission Launch Sequence...\n";
		cout << "Displaying launch sequence message.\n";
		cout << "Countdown commencing:\n";
		for (int i = 5; i > 0; --i) {
			cout << i << "...\n";
			this_thread::sleep_for(std::chrono::seconds(1));
		}
		cout << "Ignition and Liftoff! Spacecraft engines firing.\n";
		cout << "Mission Status Update: Spacecraft has left Earth's orbit and entered interplanetary trajectory towards Mars.\n";

		cout << "\n--- Mission Underway ---\n";
		while (!missionOver) {
			missionDuration++;

			if (currentFuel <= 0) {
				cout << "\nDay " << missionDuration << ": CRITICAL FAILURE! Spacecraft ran out of fuel.\n";
				missionOver = true;
				missionSuccess = false;
				continue;
			}
			if (missionDuration > EXPECTED_MAX_DURATION_DAYS) {
				cout << "\nDay " << missionDuration << ": MISSION FAILURE! Exceeded maximum expected duration of "
				     << EXPECTED_MAX_DURATION_DAYS << " days.\n";
				missionOver = true;
				missionSuccess = false;
				continue;
			}

			int dailyDist = getRandomInt(MIN_DAILY_DIST_KM, MAX_DAILY_DIST_KM);
			int dailyFuel = getRandomInt(MIN_FUEL_CONSUMPTION_L, MAX_FUEL_CONSUMPTION_L);

			if (currentFuel < dailyFuel) {
				dailyFuel = static_cast<int>(currentFuel);
				cout << "WARNING: Low fuel! Attempting to burn remaining " << dailyFuel << "L of fuel.\n";
			}
			currentFuel -= dailyFuel;


			distanceTraveled += dailyDist;


			if (distanceTraveled >= DISTANCE_TO_MARS_KM) {
				distanceTraveled = DISTANCE_TO_MARS_KM;
				missionOver = true;
			}

			long long remainingDistance = DISTANCE_TO_MARS_KM - distanceTraveled;
			if (remainingDistance < 0) remainingDistance = 0;

			cout << "Day " << missionDuration << ": ";
			cout << "Traveled " << dailyDist << " km. ";
			cout << "Consumed " << dailyFuel << " L fuel. ";
			cout << "Fuel Left: " << static_cast<int>(currentFuel) << " L. ";
			cout << "Dist to Mars: " << remainingDistance << " km.\n";

			if (!missionOver && currentFuel > 0 && currentFuel < LOW_FUEL_WARNING_THRESHOLD) {
				cout << "ALERT: Fuel levels are critically low (" << static_cast<int>(currentFuel) << " L remaining)!\n";
			}


		}
		cout << "\n--- Mission Completion Status ---\n";

		if (distanceTraveled >= DISTANCE_TO_MARS_KM &&
		        currentFuel > 0 &&
		        missionDuration <= EXPECTED_MAX_DURATION_DAYS) {
			missionSuccess = true;
		} else {
			missionSuccess = false;
		}

		if (missionSuccess) {
			cout << "MISSION SUCCESSFUL!\n";
			cout << "Spacecraft arrived at Mars in " << missionDuration << " days ";
			cout << "(within the expected " << EXPECTED_MAX_DURATION_DAYS << " days) ";
			cout << "with " << static_cast<int>(currentFuel) << " L of fuel remaining.\n";
		} else {
			cout << "MISSION UNSUCCESSFUL.\n";
			if (distanceTraveled < DISTANCE_TO_MARS_KM && currentFuel <= 0) {
				cout << "Reason: Ran out of fuel before reaching Mars.\n";
			} else if (missionDuration > EXPECTED_MAX_DURATION_DAYS) {
				cout << "Reason: Exceeded expected mission duration of " << EXPECTED_MAX_DURATION_DAYS << " days.\n";
			} else if (distanceTraveled >= DISTANCE_TO_MARS_KM && currentFuel <= 0) {
				cout << "Reason: Reached Mars but ran out of fuel upon arrival or earlier.\n";
			} else if (distanceTraveled >= DISTANCE_TO_MARS_KM && missionDuration > EXPECTED_MAX_DURATION_DAYS) {

				cout << "Reason: Reached Mars but exceeded the expected mission duration.\n";
			}

			cout << "Mission concluded after " << missionDuration << " days.\n";
			if(distanceTraveled < DISTANCE_TO_MARS_KM) {
				cout << "Final distance traveled: " << distanceTraveled << " km ("
				          << (DISTANCE_TO_MARS_KM - distanceTraveled) << " km short of Mars).\n";
			}
		}

		cout << "--- End of Mars Mission Simulation ---\n";
	}


int main() {

	srand(static_cast<unsigned int>(time(0)));

	
	runMarsMission();


}
