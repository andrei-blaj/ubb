import java.util.ArrayList;
import java.util.List;

public class main {

    public static void main(String[] args)
    {

        List<Emotion> emotionList = new ArrayList<>();

        Emotion emotion1 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion2 = new Emotion("Fear", EmotionType.Fear);
        Emotion emotion3 = new Emotion("Sadness", EmotionType.Sadness);
        Emotion emotion4 = new Emotion("Fear", EmotionType.Fear);
        Emotion emotion5 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion6 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion7 = new Emotion("Sadness", EmotionType.Sadness);

        emotionList.add(emotion1);
        emotionList.add(emotion2);
        emotionList.add(emotion3);
        emotionList.add(emotion4);
        emotionList.add(emotion5);
        emotionList.add(emotion6);
        emotionList.add(emotion7);

        ListEmotions listEmotions = new ListEmotions(emotionList);

        int joy = listEmotions.howGivenManyEmotionTypeInListEmotions(EmotionType.Joy);
        int fear = listEmotions.howGivenManyEmotionTypeInListEmotions(EmotionType.Fear);
        int sadness = listEmotions.howGivenManyEmotionTypeInListEmotions(EmotionType.Sadness);

        System.out.println("Joy: " + joy);
        System.out.println("Fear: " + fear);
        System.out.println("Sadness: " + sadness);

        emotionList = listEmotions.predominantEmotion();

        System.out.println("\n\n");
        for (Emotion e: emotionList) {
            System.out.println(e.getEmotionType() + " ");
        }

        listEmotions.eliminateAllProvidedEmotion(EmotionType.Joy);
        joy = listEmotions.howGivenManyEmotionTypeInListEmotions(EmotionType.Joy);
        System.out.println("\nJoy: " + joy);
    }

}
