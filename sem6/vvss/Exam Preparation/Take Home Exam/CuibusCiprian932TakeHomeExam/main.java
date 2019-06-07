import java.util.ArrayList;
import java.util.List;

public class main {

    public static void main(String[] args){
        List<Emotion> lEmotions = new ArrayList<>();
        Emotion eA = new Emotion("Anger", EmotionType.Anger);
        lEmotions.add(eA);
        Emotion eS = new Emotion("Sadness", EmotionType.Sadness);
        lEmotions.add(eS);
        Emotion eJ = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eJ);
        Emotion eD = new Emotion("Disgust", EmotionType.Disgust);
        lEmotions.add(eD);
        Emotion eF = new Emotion("Joy", EmotionType.Joy);
        lEmotions.add(eF);

        ListEmotions le = new ListEmotions(lEmotions);
        System.out.println("Joy instances in the array: " + le.howGivenManyEmotionTypeInListEmotions(EmotionType.Joy));
        System.out.println("Sadness instances in the array: " + le.howGivenManyEmotionTypeInListEmotions(EmotionType.Sadness));
        System.out.println("Fear instances in the array: " + le.howGivenManyEmotionTypeInListEmotions(EmotionType.Fear));
    }
}
