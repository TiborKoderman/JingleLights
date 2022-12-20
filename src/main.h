class Interval{
  private:
    int interval;
    int lastTime;
  public:
    Interval(int interval) {
      this->interval = interval;
      this->lastTime = millis();
    }

    bool isReady() {
      if (millis() - this->lastTime > this->interval) {
        this->lastTime = millis();
        return true;
      }
      return false;
    }
};