public class Emotion {

    private String description;

    private EmotionType emotionType;

    public Emotion(String d, EmotionType et){
        this.description = d;
        this.emotionType = et;
    }
    public String getDesc() {
        return description;
    }

    public void setDesc(String d) {
        this.description = d;
    }
    public EmotionType getEmotionType() {
        return emotionType;
    }

    public void EmotionType(EmotionType et) {
        this.emotionType = et;
    }

    public String toString() {
        return "Emotion: " + emotionType +". Description:"+ description;
    }


    public boolean equals(Emotion e) {
        return emotionType.equals(e.getEmotionType());
    }

}
