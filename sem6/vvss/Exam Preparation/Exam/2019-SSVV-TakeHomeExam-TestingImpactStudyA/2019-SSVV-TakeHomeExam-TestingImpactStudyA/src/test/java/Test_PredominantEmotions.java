import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;


public class Test_PredominantEmotions {

    @Test
    public void Test_PredominantJoy_predominantEmotion(){
        System.out.println("Test .... Test_PredominantJoy_predominantEmotion ... ");
        List<Emotion> testLstEmotions = new ArrayList<Emotion>();
        List lEmotions = new ArrayList<Emotion>();
        ListEmotions le = new ListEmotions(lEmotions);

        List<Emotion> lstPE = le.predominantEmotion();
        //System.out.println("Number of Predominant Emotions="+lstPE.size());
        assertEquals(lstPE.size(), 0);
    }

    @Test
    public void Test_PredominantEmotion_PredominantOne() {
        System.out.println("Test ... Test_PredominantEmotion_PredominantOne ...");
        List<Emotion> testLstEmotions = new ArrayList<Emotion>();

        Emotion emotion1 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion2 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion3 = new Emotion("Fear", EmotionType.Fear);
        Emotion emotion4 = new Emotion("Anger", EmotionType.Anger);

        testLstEmotions.add(emotion1);
        testLstEmotions.add(emotion2);
        testLstEmotions.add(emotion3);
        testLstEmotions.add(emotion4);

        ListEmotions le = new ListEmotions(testLstEmotions);

        List<Emotion> lstPE = le.predominantEmotion();
        assertEquals(lstPE.size(), 1);
    }

    @Test
    public void Test_PredominantEmotion_PredominantMultiple() {
        System.out.println("Test ... Test_PredominantEmotion_PredominantMultiple ...");
        List<Emotion> testLstEmotions = new ArrayList<Emotion>();

        Emotion emotion1 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion2 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion3 = new Emotion("Fear", EmotionType.Fear);
        Emotion emotion4 = new Emotion("Fear", EmotionType.Fear);
        Emotion emotion5 = new Emotion("Anger", EmotionType.Anger);

        testLstEmotions.add(emotion1);
        testLstEmotions.add(emotion2);
        testLstEmotions.add(emotion3);
        testLstEmotions.add(emotion4);
        testLstEmotions.add(emotion5);

        ListEmotions le = new ListEmotions(testLstEmotions);

        List<Emotion> lstPE = le.predominantEmotion();
        for(Emotion emotion: lstPE) {
            System.out.println(emotion);
        }
        assertEquals(lstPE.size(), 2);
    }

    @Test
    public void Test_PredominantEmotion_PredominantAll() {
        System.out.println("Test ... Test_PredominantEmotion_PredominantAll ...");
        List<Emotion> testLstEmotions = new ArrayList<Emotion>();

        Emotion emotion1 = new Emotion("Joy", EmotionType.Joy);
        Emotion emotion2 = new Emotion("Sadness", EmotionType.Sadness);
        Emotion emotion3 = new Emotion("Anger", EmotionType.Anger);
        Emotion emotion4 = new Emotion("Disgust", EmotionType.Disgust);
        Emotion emotion5 = new Emotion("Fear", EmotionType.Fear);


        testLstEmotions.add(emotion1);
        testLstEmotions.add(emotion2);
        testLstEmotions.add(emotion3);
        testLstEmotions.add(emotion4);
        testLstEmotions.add(emotion5);

        ListEmotions le = new ListEmotions(testLstEmotions);

        List<Emotion> lstPE = le.predominantEmotion();
        for(Emotion emotion: lstPE) {
            System.out.println(emotion);
        }
        assertEquals(lstPE.size(), testLstEmotions.size());
    }

}
