#include <iostream>
#include <vector>

#include "CheckIn.hpp"
#include "Database.hpp"
#include "Exercise.hpp"
#include "Member.hpp"
#include "Payment.hpp"
#include "WorkoutPlan.hpp"

int insertMember(Database& db, const Member& member) {
    Statement stmt(db.handle(),
                   "INSERT INTO members(name, cpf, phone, pix) VALUES (?, ?, ?, ?);");
    stmt.bindText(1, member.name());
    stmt.bindText(2, member.cpf());
    stmt.bindText(3, member.phone());
    stmt.bindText(4, member.pix());
    stmt.step();
    // static_cast to convert sqlite3_int64 to int
    return static_cast<int>(sqlite3_last_insert_rowid(db.handle()));
}

void insertPayment(Database& db, int memberId, const Payment& payment) {
    Statement stmt(
        db.handle(),
        "INSERT INTO payments(member_id, amount, date, duration) VALUES (?, ?, ?, ?);");
    stmt.bindInt(1, memberId);
    stmt.bindDouble(2, payment.amount());
    stmt.bindText(3, payment.date());
    stmt.bindText(4, payment.duration());
    stmt.step();
}

void insertCheckIn(Database& db, int memberId, const CheckIn& checkIn) {
    Statement stmt(db.handle(),
                   "INSERT INTO checkins(member_id, date, time) VALUES (?, ?, ?);");
    stmt.bindInt(1, memberId);
    stmt.bindText(2, checkIn.date());
    stmt.bindText(3, checkIn.time());
    stmt.step();
}

int insertWorkoutPlan(Database& db, int memberId, const WorkoutPlan& plan) {
    Statement planStmt(db.handle(),
                       "INSERT INTO workout_plans(member_id) VALUES (?);");
    planStmt.bindInt(1, memberId);
    planStmt.step();
    int planId = static_cast<int>(sqlite3_last_insert_rowid(db.handle()));

    const auto& days = plan.plan();
    for (size_t i = 0; i < days.size(); ++i) {
        Statement dayStmt(db.handle(),
                          "INSERT INTO workout_plan_days(plan_id, day_index) VALUES (?, ?);");
        dayStmt.bindInt(1, planId);
        dayStmt.bindInt(2, static_cast<int>(i));
        dayStmt.step();
        int dayId = static_cast<int>(sqlite3_last_insert_rowid(db.handle()));

        for (const auto& exercise : days[i]) {
            Statement exStmt(
                db.handle(),
                "INSERT INTO exercises(day_id, name, sets, reps, weight) "
                "VALUES (?, ?, ?, ?, ?);");
            exStmt.bindInt(1, dayId);
            exStmt.bindText(2, exercise.name());
            exStmt.bindInt(3, exercise.sets());
            exStmt.bindInt(4, exercise.reps());
            exStmt.bindDouble(5, exercise.weight());
            exStmt.step();
        }
    }

    return planId;
}

int main() {
    try {
        Database db("gym.db");
        db.initializeSchema();

        WorkoutPlan samplePlan({
            {Exercise("Bench Press", 3, 8, 60.0), Exercise("Squat", 3, 10, 80.0)},
            {Exercise("Pull Ups", 4, 6, 0.0), Exercise("Plank", 3, 1, 0.0)},
        });

        Member member(
            "Alice Smith",
            "12345678900",
            "+55 11 99999-0000",
            "alice@pix",
            {Payment(120.0, "2024-05-01", "Monthly")},
            {CheckIn("2024-05-02", "09:00:00")},
            samplePlan);

        int memberId = insertMember(db, member);

        for (const auto& payment : member.payments()) {
            insertPayment(db, memberId, payment);
        }
        for (const auto& checkIn : member.checkins()) {
            insertCheckIn(db, memberId, checkIn);
        }
        insertWorkoutPlan(db, memberId, member.workoutPlan());

        Statement countMembers(db.handle(), "SELECT COUNT(*) FROM members;");
        countMembers.step();
        std::cout << "Members in DB: " << countMembers.columnInt(0) << "\n";

        Statement countPayments(db.handle(), "SELECT COUNT(*) FROM payments;");
        countPayments.step();
        std::cout << "Payments in DB: " << countPayments.columnInt(0) << "\n";

        Statement countCheckins(db.handle(), "SELECT COUNT(*) FROM checkins;");
        countCheckins.step();
        std::cout << "Check-ins in DB: " << countCheckins.columnInt(0) << "\n";

        Statement countExercises(db.handle(), "SELECT COUNT(*) FROM exercises;");
        countExercises.step();
        std::cout << "Exercises in DB: " << countExercises.columnInt(0) << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
